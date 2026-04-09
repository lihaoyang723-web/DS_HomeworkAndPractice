#include "simulator.h"

Simulator::Simulator() : pc(0) {
}

void Simulator::run(const int max_steps) {
    int step = 0;
    Status status = Status::AOK;
    for (step = 0; step < max_steps && status == Status::AOK; step++) {
        status = next_instruction();
    }
    report_stopped(step, status);
}

static uint8_t get_hi4(const uint8_t pack) { return (pack >> 4) & 0xF; }
static uint8_t get_lo4(const uint8_t pack) { return pack & 0xF; }

Status Simulator::next_instruction() {
    uint64_t next_pc = pc;

    // get code and function (1 byte)
    const std::optional<uint8_t> codefun = memory.get_byte(next_pc);
    if (!codefun) {
        report_bad_inst_addr();
        return Status::ADR;
    }
    const auto icode = static_cast<InstructionCode>(get_hi4(codefun.value()));
    uint8_t ifun = get_lo4(codefun.value());
    next_pc++;

    // execute the instruction
    switch (icode) {
        case InstructionCode::HALT: // 0:0
        {
            return Status::HLT;
        }
        case InstructionCode::NOP: // 1:0
        {
            pc = next_pc;
            return Status::AOK;
        }
        case InstructionCode::RRMOVQ: // 2:x regA:regB
        {
            const std::optional<uint8_t> regs = memory.get_byte(next_pc);
            if (!regs) {
                report_bad_inst_addr();
                return Status::ADR;
            }

            const uint8_t reg_a = get_hi4(regs.value());
            const uint8_t reg_b = get_lo4(regs.value());
            if (error_invalid_reg(reg_a)) return Status::INS;
            if (error_invalid_reg(reg_b)) return Status::INS;
            next_pc++;

            if (cc.satisfy(static_cast<Condition>(ifun))) {
                registers[reg_b] = registers[reg_a];
            }
            pc = next_pc;
            return Status::AOK;
        }
        case InstructionCode::IRMOVQ:
        {
            const std::optional<uint8_t> regs = memory.get_byte(next_pc);
            if (!regs) {
                report_bad_inst_addr();
                return Status::ADR;
            }
            const uint8_t reg_a = get_hi4(regs.value());
            const uint8_t reg_b = get_lo4(regs.value());
            if (error_valid_reg(reg_a)) return Status::INS;
            if (error_invalid_reg(reg_b)) return Status::INS;
            next_pc ++;
            const std::optional<uint64_t> imm = memory.get_long(next_pc);
            if(!imm)
            {
                report_bad_inst_addr();
                return Status::ADR;
            }
            registers[reg_b] = imm.value();
            pc = next_pc + 8;
            return Status::AOK;
        } // 3:0 F:regB imm
        case InstructionCode::RMMOVQ:
        {
            const std::optional<uint8_t> regs = memory.get_byte(next_pc);
            if (!regs) {
                report_bad_inst_addr();
                return Status::ADR;
            }
            const uint8_t reg_a = get_hi4(regs.value());
            const uint8_t reg_b = get_lo4(regs.value());
            if (error_invalid_reg(reg_a)) return Status::INS;
            if (error_invalid_reg(reg_b)) return Status::INS;
            next_pc ++;
            std::optional<uint64_t> imm = memory.get_long(next_pc);
            if(!imm)
            {
                report_bad_inst_addr();
                return Status::ADR;
            }
            imm.value() += registers[reg_b];
            if(!memory.set_long(imm.value(), registers[reg_a]))
            {
                report_bad_data_addr(imm.value());
                return Status::ADR;
            }
            pc = next_pc + 8;
            return Status::AOK;
        } // 4:0 regA:regB imm
        case InstructionCode::MRMOVQ:
        {
            const std::optional<uint8_t> regs = memory.get_byte(next_pc);
            if (!regs) {
                report_bad_inst_addr();
                return Status::ADR;
            }
            const uint8_t reg_a = get_hi4(regs.value());
            const uint8_t reg_b = get_lo4(regs.value());
            if (error_invalid_reg(reg_a)) return Status::INS;
            if (error_invalid_reg(reg_b)) return Status::INS;
            next_pc ++;
            std::optional<uint64_t> imm = memory.get_long(next_pc);
            if(!imm)
            {
                report_bad_inst_addr();
                return Status::ADR;
            }
            imm.value() += registers[reg_b];
            const std::optional<uint64_t> data = memory.get_long(imm.value());
            if(!data)
            {
                report_bad_data_addr(imm.value());
                return Status::ADR;
            }
            registers[reg_a] = data.value();
            pc = next_pc + 8;
            return Status::AOK;
        } // 5:0 regA:regB imm
        case InstructionCode::ALU: 
        {
            const std::optional<uint8_t> regs = memory.get_byte(next_pc);
            if (!regs) {
                report_bad_inst_addr();
                return Status::ADR;
            }
            const uint8_t reg_a = get_hi4(regs.value());
            const uint8_t reg_b = get_lo4(regs.value());
            if (error_invalid_reg(reg_a)) return Status::INS;
            if (error_invalid_reg(reg_b)) return Status::INS;
            next_pc ++;
            uint64_t val_a = registers[reg_a];
            uint64_t val_b = registers[reg_b];
            uint64_t result;
            switch (static_cast<AluOp>(ifun)) {
                case AluOp::ADD:
                    result = val_b + val_a;
                    break;
                case AluOp::SUB:
                    result = val_b - val_a;
                    break;
                case AluOp::AND:
                    result = val_b & val_a;
                    break;
                case AluOp::XOR:
                    result = val_b ^ val_a;
                    break;
                default:
                    report_bad_inst(codefun.value());
                    return Status::INS;
            }
            registers[reg_b] = result;
            cc = ConditionCodes::compute(static_cast<AluOp>(ifun), val_a, val_b, result);
            pc = next_pc;
            return Status::AOK;
        }// 6:x regA:regB
        case InstructionCode::JMP: 
        {
            if(cc.satisfy(static_cast<Condition>(ifun)))
            {
                std::optional<uint64_t> imm = memory.get_long(next_pc);
                if(!imm)
                {
                    report_bad_inst_addr();
                    return Status::ADR;
                }
                pc = imm.value();
            }
            else
            {
                pc = next_pc + 8;
            }
            return Status::AOK;
        }
        // 7:x imm
        case InstructionCode::CALL: 
        {
                std::optional<uint64_t> imm = memory.get_long(next_pc);
                    if(!imm)
                    {
                        report_bad_inst_addr();
                        return Status::ADR;
                    }
                    uint64_t ret_addr = next_pc + 8;
                    if(!memory.set_long(registers[RegId::RSP] - 8, ret_addr))
                    {
                        report_bad_stack_addr(registers[RegId::RSP] - 8);
                        return Status::ADR;
                    }
                    registers[RegId::RSP] -= 8;
                    pc = imm.value();
                return Status::AOK;
        }
        // 8:0 imm
        case InstructionCode::RET:
        {
            uint64_t stack_addr = registers[RegId::RSP];
            registers[RegId::RSP] += 8;
            const std::optional<uint64_t> ret_addr = memory.get_long(stack_addr);
            if (!ret_addr) {
                report_bad_stack_addr(stack_addr);
                return Status::ADR;
            }
            pc = ret_addr.value();
            return Status::AOK;
        }// 9:0
        case InstructionCode::PUSHQ: {
            const std::optional<uint8_t> regs = memory.get_byte(next_pc);
            if (!regs) {
                report_bad_inst_addr();
                return Status::ADR; 
            }
            const uint8_t reg_a = get_hi4(regs.value());
            const uint8_t reg_b = get_lo4(regs.value());
            if (error_invalid_reg(reg_a)) return Status::INS;
            if (reg_b != 0xF) return Status::INS;  
            next_pc++;
            uint64_t val_a = registers[reg_a];
            if(!memory.set_long(registers[RegId::RSP] - 8, val_a))
            {
                report_bad_stack_addr(registers[RegId::RSP] - 8);
                return Status::ADR;     
            }
            registers[RegId::RSP] -= 8;
            pc = next_pc;
            return Status::AOK;
    }
            // A:0 regA:F
        case InstructionCode::POPQ: {
            const std::optional<uint8_t> regs = memory.get_byte(next_pc);
            if (!regs) {
                report_bad_inst_addr();
                return Status::ADR;
            }
            const uint8_t reg_a = get_hi4(regs.value());
            const uint8_t reg_b = get_lo4(regs.value());
            if (error_invalid_reg(reg_a)) return Status::INS;
            if (reg_b != 0xF) return Status::INS;
            next_pc++;
            const std::optional<uint64_t> val = memory.get_long(registers[RegId::RSP]);
            if (!val) {
                report_bad_stack_addr(registers[RegId::RSP]);
                return Status::ADR;
            }
            registers[reg_a] = val.value();
            if (reg_a != 4) {
                registers[RegId::RSP] += 8;
            }
            pc = next_pc;
            return Status::AOK;
        }
            // B:0 regA:F
        default:
            report_bad_inst(codefun.value());
            return Status::INS;
    }
}

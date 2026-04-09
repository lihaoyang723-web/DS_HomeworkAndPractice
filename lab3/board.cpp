#include <iostream>

#include "board.h"
#include "queue.h"

Board::Board(const int num_disk) : /* TODO */ num_disk(num_disk),rods{Rod(num_disk,0),Rod(num_disk,1),Rod(num_disk,2)},disks(nullptr){
    // TODO
}

Board::~Board() {
    // TODO

}

void Board::draw() {
    Canvas canvas {};
    canvas.reset();
    // TODO
}

void Board::move(int from, int to, const bool log) {
    // TODO
}

bool Board::win() const {
    // TODO
    return rods[1].full();
}

void solve(
    const int n,
    const int src,
    const int buf,
    const int dest,
    Queue<std::pair<int, int>> &solution
) {
    // TODO
}

void Board::autoplay() {
    // TODO
}

#include "rod.h"
#include <cstddef>

Rod::Rod(const int capacity, const int id) : /* TODO */capacity(capacity),id(id) { }

bool Rod::push(const Disk d) {
    // TODO
    if (full()) {
        return false;
    }
    stack.push(d);
    return true;
}

const Disk &Rod::top() {
    // TODO
    return stack.top();
}

void Rod::pop() {
    // TODO
    stack.pop();
}

size_t Rod::size() const {
    // TODO
    return stack.size();
}

bool Rod::empty() const {
    // TODO
    return stack.empty();
}
bool Rod::full() const {
    // TODO
    return stack.size() == capacity;
}
void Rod::draw(Canvas &canvas) {
    Stack<const Disk> temp;
    while (!stack.empty()) {
        temp.push(stack.top());
        stack.pop();
    }
    int level = 0;
    while (!temp.empty()) {
        const Disk& disk = temp.top();
        disk.draw(canvas, level, id);
        stack.push(disk);
        temp.pop();
        level++;
    }
}

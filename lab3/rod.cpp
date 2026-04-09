#include "rod.h"
#include <cstddef>

Rod::Rod(const int capacity, const int id) : /* TODO */capacity(capacity),id(id) { }

bool Rod::push(const Disk d) {
    // TODO
    stack.push(d);
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
    // TODO
    canvas.draw();
}

#ifndef QUEUE_IMPL_H
#define QUEUE_IMPL_H
#include "queue.h"
#include <cassert>
#include <cstddef>

template <typename T>
Queue<T>::Queue() : sz(0), head(nullptr), tail(nullptr) { }

template <typename T>
Queue<T>::~Queue() {
    Node<T> *tmp = head;
    while(tmp != nullptr)
    {
        Node<T> *q = tmp;
        tmp = tmp -> next;
        delete q;
    }
    head = nullptr;
    tail = nullptr;
    sz = 0;
}

template <typename T>
void Queue<T>::push(T t) {
    if (empty()) {
        head = new Node<T>(t);
        tail = head;
    } else {
        tail->next = new Node<T>(t);
        tail = tail->next;
    }
    sz++;
 }

template <typename T>
void Queue<T>::pop() {
    assert(!empty());
    Node <T> * tmp = head;
    head = head -> next;
    sz --;
    delete tmp;
    if (head == nullptr) {
        tail = nullptr;
    }
}

template <typename T>
T &Queue<T>::front() {
    assert(!empty());
    return head -> val;
}

template <typename T>
bool Queue<T>::empty() const {
    // TODO
    return sz == 0;
}

template <typename T>
size_t Queue<T>::size() const {
    // TODO
    return sz;
}
#endif

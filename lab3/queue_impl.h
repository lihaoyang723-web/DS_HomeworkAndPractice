#ifndef QUEUE_IMPL_H
#define QUEUE_IMPL_H
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
    // TODO
    tail -> next = new Node<T>(t,nullptr);
    tail = tail -> next;
    sz ++;
 }

template <typename T>
void Queue<T>::pop() {
    // TODO
    Node <T> * tmp = head;
    head = head -> next;
    sz --;
    delete tmp;
}

template <typename T>
T &Queue<T>::front() {
    // TODO
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

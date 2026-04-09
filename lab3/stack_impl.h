#ifndef STACK_IMPL_H
#define STACK_IMPL_H
#include <cassert>
#include <cstddef>

template <typename T>
Stack<T>::Stack() : sz(0), head(nullptr) { }

template <typename T>
Stack<T>::~Stack() {
    Node<T>*tmp = head;
    while(tmp != nullptr)
    {
        Node<T>*q = tmp;
        tmp = tmp -> next;
        delete q;
    }
    head = nullptr;
    sz = 0;
}

template <typename T>
void Stack<T>::push(T t) {
    Node<T>*tmp = new Node<T>;
    tmp -> val = t;
    tmp -> next = head;
    head = tmp;
    sz ++;
}

template <typename T>
void Stack<T>::pop() {
    assert(!empty());
    Node<T>* tmp = head;
    head = head -> next;
    delete tmp;
    sz--;
}

template <typename T>
T& Stack<T>::top() {
    // TODO
    assert(!empty());
    return head -> val;
}

template <typename T>
bool Stack<T>::empty() const {
    // TODO
    if(sz == 0) return true;
    return false;
}

template <typename T>
size_t Stack<T>::size() const {
    // TODO
    return sz;
}

#endif

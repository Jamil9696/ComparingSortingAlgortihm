#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList
{
public:
    void push(const T object);
    void move(int steps = 1);
    void insert(T object);
    T get();
    T at(int i

    );

    bool empty() const;
    int size()const;
    void pop();
    void reset();

private:
    Node<T>* pTop = nullptr;
    Node<T>* pEnd = nullptr;
    Node<T>* pPos = nullptr;
};

// ================================== Functions declarations ==========================================




template <typename T>
void LinkedList<T>::push(const T object) {

    Node<T>* newNode = new Node<T>(object);

    if (pTop != nullptr) {
        pEnd->connectPnext(newNode);
        newNode->connectPprevious(pEnd);
    }
    else {
        pTop = newNode;
    }
    reset();
    pEnd = newNode;
}


template <typename T>
void LinkedList<T>::reset() {
    if (pTop == nullptr) {
        pTop = nullptr;
        pPos = nullptr;
        pEnd = nullptr;
        return;
    }
    if (pTop != nullptr) {
        if (pTop->getPnext() == nullptr) {
            pPos = pTop;
            pEnd = pTop;
        }
    }
}

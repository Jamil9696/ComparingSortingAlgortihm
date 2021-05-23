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
void LinkedList<T>::move(int zahl) {

    while (zahl < size() && zahl > 0) {
        if (pPos->getPnext() != nullptr) {
            pPos = pPos->getPnext();
        }
        zahl--;
    }
}

template <typename T>
void LinkedList<T>::insert(T Object) {

    if (pPos == pTop) {
        push(Object);
        return;
    }
    Node<T>* p = new Node<T>(Object);
    // connect P with his right and left element. We don't have to worry about the existing connections
    // we simply overwrite them

    // right connection
    //  p ----> next Node
    p->connectPnext(pPos->getPnext());
    //  p <---- next Node 
    pPos->getPnext()->connectPprevious(p);

    // left connection 
    // p -----> previous Node 
    p->connectPprevious(pPos);
    // p <---- previous Node
    pPos->connectPnext(p);

    reset();
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

template <typename T>
bool LinkedList<T>::empty()const {

    return pTop == nullptr ? true : false;
}

template <typename T>
int LinkedList<T>::size()const {

    return pTop->getSize();
}
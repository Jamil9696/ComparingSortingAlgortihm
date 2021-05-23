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
        pEnd->connect(newNode);
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

    p->connect(pPos->getPnext());
    pPos->deconnect();
    pPos->connect(p);
    reset();
}

template <typename T>
T LinkedList<T>::get() {

    if (!empty()) {
        return pPos->getData();
    }
    else {
        throw std::string{ "invalid operation.\nTrying to return the last element of an empty List" };
    }
}

template <typename T>
T LinkedList<T>::at(int pos) {

    if (empty() && pos >= size()) throw std::string{ "invalid operation.\nTrying to return an invalid element " };

    Node<T>* tmp = pTop;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->getPnext();
    }
    return tmp->getData();

}

template <typename T>
bool LinkedList<T>::empty()const {

    return pTop == nullptr ? true : false;
}

template <typename T>
int LinkedList<T>::size()const {

    return pTop->getSize();
}

template <typename T>
void LinkedList<T>::pop() {

    Node<T>* tmp = pTop;

    // looking for the penultimate Node 
    for (int i = 1; tmp->getPnext() != nullptr && i < size() - 1; i++) {
        tmp = tmp->getPnext();
    }
    // delete pNext which is currently pointing to our last element
    if (tmp->getPnext() != nullptr) {

        delete tmp->getPnext();
        tmp->deconnect();
        pEnd = tmp;
        pPos = pTop;
        return;
    }
    delete pTop;
    pTop = nullptr;
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

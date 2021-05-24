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
    void del();
    T get();
    T at(int i);

    bool empty() const;
    int size()const;
    void pop();
    void popAt();
private:
    void checkPointer();

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
    checkPointer();
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

    checkPointer();
}

template<typename T>
void LinkedList<T>::del()
{
    if (pPos == pTop) {
        pPos = pTop->getPnext();
        pTop->deconnectPnext();
        delete pTop;
        pTop = pPos;
        return;
    }

    else if(pPos == pEnd)
    {
        Node<T>* tmp = pPos->getPprevious();
        delete pPos;
        pPos = tmp;
        pEnd = tmp;
        return;

    }

    Node<T>* tmp = pPos->getPnext();
    pPos->getPprevious()->connectPnext(pPos->getPnext());
    pPos->getPnext()->connectPprevious(pPos->getPprevious());
    delete pPos;
    pPos = tmp;
    checkPointer();
}

template <typename T>
T LinkedList<T>::at(int pos) {

    if (empty() || pos >= size()) throw std::string{ "invalid operation.\nTrying to return an invalid element " };

    Node<T>* tmp = pTop;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->getPnext();
    }
    return tmp->getData();

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
void LinkedList<T>::pop() {

    if (pEnd != pTop) {
        Node<T>* tmp = pEnd->getPprevious();
        tmp->deconnectPnext();
        delete pEnd;
        pEnd = tmp;
        pPos = pTop;
    }
    else {
        if (pTop != nullptr) {
            delete pTop;
            pTop = nullptr;
        }        
    }

    checkPointer();
}

template <typename T>
void LinkedList<T>::popAt() {

    if (pPos == pTop) return; 

    Node<T>* tmp = pPos;
    tmp->getPprevious()->connectPnext(tmp->getPnext());
    tmp->getPnext()->connectPprevious(tmp->getPprevious());
    pPos = pTop;
    delete tmp;
    delete tmp;
    checkPointer();

}



template <typename T>
void LinkedList<T>::checkPointer() {
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
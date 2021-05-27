#pragma once
#include "Node.h"

#include <iostream>

template <typename T>
class LinkedList
{
public:
    
    // add ( at the beginning )
    void add(T* object);
    // push ( at the end)
    void push( T* object);
    void insertAfter( T* object, bool sortedMode);
    void insertAfter(int step, T* object);

    // pPos
    void move(int steps = 1);
    void setToFirst();
    T* get()const;
    T* at(int i);

    // state
    bool empty() const;
    int getSize()const;

    // delete functions
    // del (at the beginning)
    void del();
    void delAt(int i);
    // pop ( at the end )
    void pop();
    // modifizierter Bubblesort
    void modifiedBubblesort();

private:
    Node<T>* pTop = nullptr;
    Node<T>* pEnd = nullptr;
    Node<T>* pPos = nullptr;
    int size = 0;
};

// ================================== Functions declarations ==========================================




template <typename T>
void LinkedList<T>::add(T* object) {


    Node<T>* newNode = new Node<T>(new T(object));
    Node<T>* tmp = pTop;

    if (pTop == nullptr) pEnd = newNode;

    pTop = newNode;
    pTop->connectPnext(tmp);

    if (tmp != nullptr) tmp->connectPprevious(pTop);
    size++;


}

template <typename T>
void LinkedList<T>::push(T* object) {
 
   
    Node<T>* newNode = new Node<T>(new T(object));


    if (pTop != nullptr) {
        pEnd->connectPnext(newNode);
        newNode->connectPprevious(pEnd);
    }
    else {

        pTop = newNode;
        
    }
    pEnd = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::move(int zahl) {
   
    while (zahl < getSize() && zahl > 0) {
        if (pPos->getPnext() != nullptr) {
            pPos = pPos->getPnext();
        }
        zahl--;
    }
}

template<typename T>
void LinkedList<T>::insertAfter(T* object, bool sortedMode)
{
    if (sortedMode) {

        for (pPos = pTop; *(pPos->getPnext()->getData()) < *object && pPos != nullptr; pPos = pPos->getPnext())
        {
        }

        insertAfter(0, object);
    }
    else {
        add(object);
    }
}


template <typename T>
void LinkedList<T>::insertAfter(int step, T* object) {

    
    move(step);

    if (pTop == nullptr || pTop == pPos) {
        add(object);
        return;
    }

    if (pPos == pEnd) {
        push(object);
        return;
    }
   
    Node<T>* p = new Node<T>(new T(object));

    p->connectPnext(pPos->getPnext());
    pPos->getPnext()->connectPprevious(p);

    p->connectPprevious(pPos);
    pPos->connectPnext(p);

    setToFirst();
    size++;
   
}

template<typename T>
void LinkedList<T>::setToFirst()
{
    pPos = pTop;
}

template <typename T>
T* LinkedList<T>::at(int pos) {

    
    if (empty() || pos >= getSize()) throw std::string{ "invalid operation.\nTrying to return an invalid element " };

    Node<T>* tmp = pTop;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->getPnext();
    }
    return tmp->getData();

}
template <typename T>
T* LinkedList<T>::get()const {

    if (!empty()) {
        return pPos->getData();
    }
    else {
        throw std::string{ "invalid operation.\nTrying to return an element of an empty List" };
    }
}

template <typename T>
void LinkedList<T>::pop() {

    if (!empty()) {
      

        if (pEnd != pTop) {
            Node<T>* tmp = pEnd->getPprevious();
            tmp->connectPnext(pEnd->getPnext());
            delete pEnd;
            pEnd = tmp;
            size--;
        }
        else {
            if (pTop != nullptr) {
                delete pTop;
                pTop = nullptr;
                size--;
            }
        }
        
    }
    setToFirst();
    
}

template<typename T>
void LinkedList<T>::del()
{
    setToFirst();

    if (!empty()) {
        pPos = pTop->getPnext();
        delete pTop;
        pTop = pPos;
        size--;
        return;
    }

}

template<typename T>
void LinkedList<T>::delAt(int i) {


    if (!empty()) {
        setToFirst();

        move(i);

        if (pPos == pTop) {
            del();
            return;
        }

        if (pPos == pEnd)
        {
            pop();
            return;
        }

        pPos->getPprevious()->connectPnext(pPos->getPnext());
        pPos->getPnext()->connectPprevious(pPos->getPprevious());

        delete pPos;
        size--;
        setToFirst();
    }
}

template<typename T>
void LinkedList<T>::modifiedBubblesort()
{
    // modified bubblesort https://www.youtube.com/watch?v=idPPDMNkyNk&t=750s
    bool changeIsDone = true;
    Node<T>* lastPtr = pEnd;
    for (int i = 0; i < getSize() && changeIsDone; i++) {

        changeIsDone = false;
        for (setToFirst(); pPos != lastPtr && lastPtr->getPprevious() != nullptr; move()) {

            if (*pPos > *(pPos->getPnext())) {

                T* tmp = pPos->getData();
                pPos->setData(pPos->getPnext()->getData());
                pPos->getPnext()->setData(tmp);

                changeIsDone = true;
            }

        }
        lastPtr = lastPtr->getPprevious();
    }

    setToFirst();
}

template <typename T>
bool LinkedList<T>::empty()const {

    return pTop == nullptr ? true : false;
}

template <typename T>
int LinkedList<T>::getSize()const {

    return size;
}
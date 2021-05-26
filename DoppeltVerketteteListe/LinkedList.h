#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList
{
public:
    
    // add
    void add(T* object);
    void push( T* object);
    void insert( T* object, bool sortedMode);
    void insert(int step, T* object);

    // pPos
    void move(int steps = 1);
    void setToFirst();
    T* get();
    T* at(int i);

    // state
    bool empty() const;
    int size()const;

    // delete functions
    void del();
    void delAt(int i);
    void pop();
    void popAt(int i);

    void sortedFunction();

private:
    Node<T>* pTop = nullptr;
    Node<T>* pEnd = nullptr;
    Node<T>* pPos = nullptr;
};

// ================================== Functions declarations ==========================================

template <typename T>
void LinkedList<T>::add(T* object) {

    
    T* newObject = new T(object);
    Node<T>* newNode = new Node<T>(newObject);
    Node<T>* tmp = pTop;

    if (pTop == nullptr) pEnd = newNode;
   
    pTop = newNode;
    pTop->connectPnext(tmp);

  if(tmp != nullptr ) tmp->connectPprevious(pTop);

      setToFirst();
   
    
}

template <typename T>
void LinkedList<T>::push( T* object) {


    T* newObject = new T(object);
    Node<T>* newNode = new Node<T>(newObject);
   

    if (pTop != nullptr) {
        pEnd->connectPnext(newNode);
        newNode->connectPprevious(pEnd);
    }
    else {

        pTop = newNode;
        setToFirst();
    }
    pEnd = newNode;
}

template <typename T>
void LinkedList<T>::move(int zahl) {

    zahl--;
    while (zahl < size() && zahl >= 0) {
        if (pPos->getPnext() != nullptr) {
            pPos = pPos->getPnext();
        }
        zahl--;
    }
}

template<typename T>
void LinkedList<T>::insert( T* object, bool sortedMode)
{
    if (sortedMode) {

        for (pPos = pTop; *(pPos->getPnext()->getData()) < *object && pPos != nullptr; pPos = pPos->getPnext())
        {
        }
        insert(0,object);
    }
    else {
        add(object);
    }
}


template <typename T>
void LinkedList<T>::insert(int step, T* object) {

    move(step);

    if (pTop == nullptr || pTop == pPos) {
        add(object);
        return;
    }

    if (pPos == pEnd) {
        push(object);
        return;
    }

 
    T* newObject = new T(object);
    Node<T>* p = new Node<T>(newObject);

    p->connectPnext(pPos->getPnext());
    pPos->getPnext()->connectPprevious(p);

    p->connectPprevious(pPos);
    pPos->connectPnext(p);

    setToFirst();
}

template<typename T>
void LinkedList<T>::setToFirst()
{
    pPos = pTop;
}

template <typename T>
T* LinkedList<T>::at(int pos) {

   
    if (empty() || pos >= size()) throw std::string{ "invalid operation.\nTrying to return an invalid element " };

    Node<T>* tmp = pTop;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->getPnext();
    }
    return tmp->getData();

}
template <typename T>
T* LinkedList<T>::get() {

    if (!empty()) {
        return pPos->getData();
    }
    else {
        throw std::string{ "invalid operation.\nTrying to return the last element of an empty List" };
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
            setToFirst();
        }
        else {
            if (pTop != nullptr) {
                delete pTop;
                pTop = nullptr;
            }
        }
    }
}

template <typename T>
void LinkedList<T>::popAt(int i) {

    move(i);
    if (pTop == pPos) {
        del();
        return;
    }

    if (pPos == pEnd){
        pop();
        return;
     }

    Node<T>* tmp = pPos;
    tmp->getPprevious()->connectPnext(tmp->getPnext());
    tmp->getPnext()->connectPprevious(tmp->getPprevious());
    setToFirst();
    delete tmp;

}

template<typename T>
void LinkedList<T>::del()
{
    if (!empty()) {
        pPos = pTop->getPnext();
        delete pTop;
        setToFirst();
        return;
    }

}

template<typename T>
void LinkedList<T>::delAt(int i) {


    if (!empty()) {

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

        Node<T>* tmp = pPos->getPnext();
        pPos->getPprevious()->connectPnext(pPos->getPnext());
        pPos->getPnext()->connectPprevious(pPos->getPprevious());
        delete pPos;
        pPos = tmp;
    }
}

template<typename T>
void LinkedList<T>::sortedFunction()
{

    bool changeIsDone = true;
    Node<T>* lastPtr = pEnd;
    for (int i = 0; i < size() && changeIsDone; i++) {
        
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
int LinkedList<T>::size()const {

    return pTop->getSize();
}
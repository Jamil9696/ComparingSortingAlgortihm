#pragma once
#include <string.h>



template <typename T>
class Node {

public:
    Node(){};
    Node(T* _data);
    ~Node() {
        delete data;
    }

    void connectPnext(Node<T>* src);
    void connectPprevious(Node<T>* src);
    void setData(T* _data);

    Node* getPnext()const;
    Node* getPprevious()const;
    T* getData()const;

    template <typename T>
    friend bool operator>(Node<T>& rValue, Node<T>& lValue) {
        return *(rValue.getData()) > *(lValue.getData());
    }

    template <typename T>
    friend bool operator<(Node<T>& rValue, Node<T>& lValue) {
        return *(rValue.getData()) < *(lValue.getData());
    }

    template <typename T>
    friend bool operator<=(Node<T>& rValue, Node<T>& lValue) {
        return *(rValue.getData()) <= *(lValue.getData());
    }

    template <typename T>
    Node<T>* operator=(const Node<T>* a){
        data = a->getData();
        pNext = a->getPnext();
        pPrevious = a->getPprevious();
        
    }
private:
    T* data = nullptr;
    Node<T>* pNext = nullptr;
    Node<T>* pPrevious = nullptr;
};


// =============================== Function Declarations ==================================

template<typename T>
Node<T>::Node(T* _data)
    :
    data(_data)
{
}


template <class T>
void Node<T>::connectPnext(Node<T>* src) {
    pNext = src;

}

template <class T>
void Node<T>::connectPprevious(Node<T>* src) {
    pPrevious = src;

}

template <class T>
Node<T>* Node<T>::getPnext()const {
    return pNext;
}

template <class T>
Node<T>* Node<T>::getPprevious()const {
    return pPrevious;
}

template <class T>
T* Node<T>::getData()const {
    return data;

}

template<typename T>
void Node<T>::setData(T* _data)
{
    data = _data;
}


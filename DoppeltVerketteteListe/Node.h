#pragma once
#pragma once

template <typename T>
class Node {
public:

    Node(const T _data);
    void storeData(T object);
    int getSize() const;
    void connectPnext(Node<T>* src);
    void connectPprevious(Node<T>* src);
    Node* getPnext()const;
    Node* getPprevious()const;
    void deconnectPnext();
    void deconnectPprevious();
    T getData()const;
    ~Node() {
        size--;

    }
private:
    T data;
    Node<T>* pNext = nullptr;
    Node<T>* pPrevious = nullptr;
    static int size;

};


// =============================== Function Declarations ==================================


template <typename T>
int Node<T>::size = 0;

template<typename T>
Node<T>::Node(const T _data)
    :
    data(_data)
{
    size++;
}


template<typename T>
void Node<T>::storeData(T object) {
    data = object;
}


template<typename T>
int Node<T>::getSize()const
{
    return size;

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
void Node<T>::deconnectPnext() {
    pNext = nullptr;
}

template <class T>
void Node<T>::deconnectPprevious() {
    pPrevious = nullptr;
}

template <class T>
T Node<T>::getData()const {
    return data;

}


#pragma once
#pragma once

template <typename T>
class Node {
public:

    Node(const T _data);
    void storeData(T object);
    int getSize() const;
    Node* nextNode(Node<T>* src);
    void connect(Node<T>* src);
    Node* getPnext()const;
    void deconnect();
    T getData()const;
    ~Node() {
        size--;
    }
private:
    T data;
    Node<T>* pNext = nullptr;
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
Node<T>* Node<T>::nextNode(Node<T>* src) {
    if (src != nullptr)
    {

        src = nextNode(src);
    }
    else
    {
        return src;
    }
}


template <class T>
void Node<T>::connect(Node<T>* src) {
    pNext = src;

}

template <class T>
Node<T>* Node<T>::getPnext()const {
    return pNext;
}

template <class T>
void Node<T>::deconnect() {
    pNext = nullptr;

}

template <class T>
T Node<T>::getData()const {
    return data;

}


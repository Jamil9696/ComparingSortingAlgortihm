#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>


template <typename T>
class LinkedList
{
public:

    // add ( at the beginning )
    void add(T* object);
    // push ( at the end)
    void push(T* object);
    void insertAfter(T* object, bool sortedMode);
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
  
    // MergeSort , HeapSort
    LinkedList<T> mergeToOne(LinkedList<T>& cpyList1, LinkedList<T>& returnList);
    void mergeSort();
    void heapSort();
    
    // show Tree structure
    int getParent(int i) { return i >> 1; }; // i / 2
    int getLeftChild(int i) { return (i << 1) + 1; }; // i * 2
    int getRightChild(int i) { return (i << 1) + 2; }; // i * 2 + 1
    

    //QuickSort
    void quickSort(int low, int high);
    void otherQuicksort(int low, int high);

private:
    void mergeSort(int begin, int end);
    void heapSort(int end);
    Node<T>* getNodePtr(int i);
    void merge(int begin, int mid , int end);
    
    void heapify(bool sortMode, int size, int i);
   
    void merge(int begin, int mid, int mid2, int end);
    int partition(int low, int high);
private:
    Node<T>* pTop = nullptr;
    Node<T>* pEnd = nullptr;
    Node<T>* pPos = nullptr;
    int size = 0;
};

// ================================== Functions declarations ==========================================




template <typename T>
void LinkedList<T>::add(T* object) {


    // deep copy 
    Node<T>* newNode = new Node<T>(new T(object));
    Node<T>* tmp = pTop;

    if (pTop == nullptr) {
        pEnd = newNode;
        pMid = newNode;
    }
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

// move pPos ( if zahl = 0 pPos position will not be updated
template <typename T>
void LinkedList<T>::move(int zahl) {

    while (zahl < getSize() && zahl > 0) {
        if (pPos->getPnext() != nullptr) {
            pPos = pPos->getPnext();
        }
        zahl--;
    }
}

// overloaded function, insert function with sort mode
template<typename T>
void LinkedList<T>::insertAfter(T* object, bool sortedMode)
{
    if (sortedMode) {

        for (setToFirst(); *(pPos->getPnext()->getData()) < *object && pPos != nullptr; move())
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


    // if step = 0  nothing happens else move pPos
    move(step);

    // when pTop == nullptr ( empty list ) or pTop == pPos, it's like calling add function. Return will interrupt this function 
    if (pTop == nullptr || pTop == pPos) {
        add(object);
        return;
    }

    // when pPos = end, it's like calling push ()
    if (pPos == pEnd) {
        push(object);
        return;
    }

    Node<T>* p = new Node<T>(new T(object));


    p->connectPnext(pPos->getPnext());
    pPos->getPnext()->connectPprevious(p);

    p->connectPprevious(pPos);
    pPos->connectPnext(p);

    setToFirst(); // reset position pointer to pTop
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
    return tmp->getData(); // return a pointer which has access to the stored item

}
template <typename T>
T* LinkedList<T>::get()const {

    if (!empty()) {
        return pPos->getData(); // return a pointer which has acces to the stored item

    }
    else {
        throw std::string{ "invalid operation.\nTrying to return an element of an empty List" };
    }
}

template <typename T>
void LinkedList<T>::pop() {

    if (!empty()) {

        // tmp = pEnd - 1, delete pEnd (last Element), pEnd = tmp
        if (pEnd != pTop) {
            Node<T>* tmp = pEnd->getPprevious();
            tmp->connectPnext(pEnd->getPnext());
            delete pEnd;
            pEnd = tmp;
            size--;
        }
        else {
            // 
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

        // same as explained in insert function
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
LinkedList<T> mergeToOne(LinkedList<T>& cpyList, LinkedList<T>& returnList) {

    int size = cpyList.getSize() + returnList.getSize();

    cpyList.setToFirst();


    for (int i = returnList.getSize(); i < size; i++) {
        returnList.push(cpyList.get());
        cpyList.move();
    }
    returnList.setToFirst();


    returnList.mergeSort(0, returnList.getSize() - 1); 

    return returnList;
}

template <typename T>
void LinkedList<T>::mergeSort() {
    mergeSort(0, size - 1);
}

template <typename T>
void LinkedList<T>::mergeSort(int l, int r) {
    
    if (l < r) {
        //left + (right - left) / 2
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

template <typename T>
void LinkedList<T>::merge(int begin, int mid, int end) {

    const int n1 = mid - begin + 1;
    const int n2 = end - mid;
    int i = 0;
    int j = 0;
    int k = begin;

    // Create temp arrays
    std::vector<T*> tmpL;
    std::vector<T*> tmpR;

    
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        
        tmpL.push_back(getNodePtr(begin + i)->getData());
       
    }
    for (int j = 0; j < n2; j++) {
        tmpR.push_back(getNodePtr(mid + 1 + j )->getData());
        
    }

    // Merge the temp arrays back into arr[l..r]
   
    pPos = getNodePtr(k);
    while (i < n1 && j < n2) {
        if (*(tmpL.at(i)) <= *(tmpR.at(j))){
            pPos->setData(tmpL.at(i++));
        }
        else {
            pPos->setData(tmpR.at(j++));
        }
        move();
       
    }

    while (i < n1) {
        pPos->setData(tmpL.at(i++));
        move();

    }
    while (j < n2) {
        pPos->setData(tmpR.at(j++));
        move();
    }

}


template <typename T>
void LinkedList<T>::heapify(bool sortMode, int size, int i) 
{
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    int large = i;

    Node<T>* parent = getNodePtr(i);

    const Node<T>* leftChild = getNodePtr(L);
    const Node<T>* rightChild = getNodePtr(R);
   
    if (L < size && *(leftChild->getData()) > *(parent->getData())) {
        large = L;

    }

    if (R < size && *(rightChild->getData()) > *(parent->getData())) {
        
        if (*(rightChild->getData()) > *(leftChild->getData())) {
            large = R;
        }
    }
   
    if (large != i) {
        
        Node<T>* parentNew = getNodePtr(large);

        T* tmp = parent->getData();
        parent->setData(parentNew->getData());
        parentNew->setData(tmp);
        
        heapify(true, size, large);
    }

}

template <typename T>
void LinkedList<T>::heapSort() {
    heapSort(size);
}

template <typename T>
void LinkedList<T>::heapSort(int size) {
   
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(false, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {

        Node<T>* bigElement = getNodePtr(0);
        Node<T>* smallElement = getNodePtr(i);

        T* tmp = bigElement->getData();
        bigElement->setData(smallElement->getData());
        smallElement->setData(tmp);
        heapify(true, i, 0);
    
    }  

}



template <typename T>
bool LinkedList<T>::empty()const {

    return pTop == nullptr ? true : false;
}

template <typename T>
int LinkedList<T>::getSize()const {

    return size;
}

template <typename T>
Node<T>* LinkedList<T>::getNodePtr(int index) {
   
    setToFirst();
      
        if (index == 0) return pTop;

        if (index == getSize()) return pEnd;

        /*if (index >= size / 2) {
            pPos = pMid;
            index = size - index;
        }*/
        move(index);
        return pPos;
    

}

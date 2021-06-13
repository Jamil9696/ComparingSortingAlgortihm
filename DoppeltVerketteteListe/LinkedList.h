#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <algorithm>

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
    // MergeSort 
    //  LinkedList* mergeToOne(LinkedList<T>& list1, LinkedList<T>& list2);
    LinkedList<T> mergeToOne(LinkedList<T>& cpyList1, LinkedList<T>& returnList);
    void mergeSort(int begin, int end);
private:
    Node<T>* getNodePtr(int i);
    void SortListPart(int begin, int end);
    void merge(int begin, int mid , int mid2, int end);

   

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
    return tmp->getData(); // return a pointer which has acces to the stored item

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
LinkedList<T> mergeToOne(LinkedList<T> &cpyList, LinkedList<T> &returnList) {

    int size = cpyList.getSize() + returnList.getSize();
    
    cpyList.setToFirst();
    
    
    for(int i = returnList.getSize(); i < size; i++){
        returnList.push(cpyList.get());
        cpyList.move();
    }
    returnList.setToFirst();
   

    returnList.mergeSort(0, returnList.getSize()); 

    return returnList;
}


template <typename T>
void LinkedList<T>::mergeSort(int begin, int end) {
    
    if ((end - begin) > 2) {
        
        int midIndex = ((begin + end) / 2); // move function beginnt ab 0 an zu zählen
        mergeSort(begin, midIndex); 
        mergeSort(midIndex+1, end);
        merge(begin, midIndex, midIndex + 1, end - 1);

    }
}

template <typename T>
void LinkedList<T>::merge(int begin, int mid, int mid2, int end) {

    Node<T>* leftStart = getNodePtr(begin);
    Node<T>* leftEnd = getNodePtr(mid);
    Node<T>* rightStart = getNodePtr(mid2); 
    Node<T>* rightEnd = getNodePtr(end);
    // sortiere Linken Teil der Liste
    SortListPart(begin, mid);
    // sortiere rechten Teil der >Liste    
    SortListPart(mid2, end);
    // merge them to one 
    std::vector<T*> tmpList;

    // 1) erstelle eine temporäre Liste
    for (; leftStart != rightEnd; leftStart = leftStart->getPnext()) {

        tmpList.push_back(leftStart->getData());  
    }
    tmpList.push_back(leftStart->getData());

    // 2) definiere ein Lambda für die Sortfunction
    const auto sorter = [](T const& a, T const& b) {

        return a < b;
    };

    std::stable_sort(tmpList.begin(), tmpList.end(), sorter);

    // 3) overwrite the old data pointers

    int i = 0;
    for (leftStart = getNodePtr(begin); leftStart != rightEnd; leftStart = leftStart->getPnext()) {

        leftStart->setData(tmpList.at(i++));
        
    }
    leftStart->setData(tmpList.at(i++));
}

template< typename T>
void LinkedList<T>::SortListPart(int _begin, int _end) {

    Node<T>* pEnd = getNodePtr(_end);
    Node<T>* pStart = nullptr;
    std::vector<T*> tmpList;

    const auto sorter = [](T const& a, T const& b) {

        return a < b;
    };

    for (pStart = getNodePtr(_begin); pStart != pEnd; pStart = pStart->getPnext()) {

        tmpList.push_back(pStart->getData());
    }
    tmpList.push_back(pStart->getData());


    std::stable_sort(tmpList.begin(), tmpList.end(),sorter);//
         
    int i = 0;
    for (pStart = getNodePtr(_begin); pStart != pEnd; pStart = pStart->getPnext()) {
        pStart->setData(tmpList.at(i++));
    }
    pStart->setData(tmpList.at(i));
    
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

    move(index);
    return pPos;

}

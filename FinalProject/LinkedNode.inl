//
// Created by Sonya Gattus on 11/20/18.
//
#include "LinkedNode.h"

template <class T>
LinkedNode<T>::LinkedNode(){
    next = nullptr;
    this->item= nullptr;

}

template <class T>
LinkedNode<T>::LinkedNode(const LinkedNode& nodeToCopy){

    next = nullptr;
    //T newCar=T(nodeToCopy.getCar());
    item= nullptr;
}


template <class T>
LinkedNode<T>* LinkedNode<T>::getNext(){
    return next;
}

template <class T>
T LinkedNode<T>::getItem() {
    return *item;
}


template <class T>
void LinkedNode<T>::setNext(LinkedNode* newNext){
    next = newNext;
}


template <class T>
void LinkedNode<T>::setItem(T newItem){
    this->item=new T(newItem);
}

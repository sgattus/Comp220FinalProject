//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <string>
#include "Song.h"
#include "List.h"



template <class T>
class LinkedNode {

private:
    T* item;
    LinkedNode* next;

public:
    LinkedNode();
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    T* getItem();
    LinkedNode* getNext();
    void setItem(Song newItem);
    void setNext(LinkedNode* newNext);
    void setList(List* newItem);
};

#include "LinkedNode.inl"


#endif //LINKEDNODE_H

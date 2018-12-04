#include "PlayListMap.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Constructor
 */

PlayListMap::PlayListMap() {
    head= nullptr;
    end= nullptr;

    size=0;
}

void PlayListMap::put(List& value){
    LinkedNode<List>* newNode=new LinkedNode<List>();
    newNode->setList(&value);
    if(head== nullptr){
        head = newNode;
        end = newNode;
        size +=1;
    }
    else if(this->containsKey(value.getName())==true){
        LinkedNode<List>* temp=head;
        for(int i=0; i<size; i++){
            if(temp->getItem()->getName()==value.getName()) {
                temp->setList(&value);
            }
            else{
                temp=temp->getNext();
            }
        }
        temp= nullptr;


    }

    else{
        end->setNext(newNode);
        end=newNode;
        size +=1;

    }
}










List* PlayListMap::get(std::string name){
    LinkedNode<List> *temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->getItem()->getName()==name) {
            return temp->getItem();
        } else {
            temp = temp->getNext();
        }
    }
    temp = nullptr;
    //} else {
    if(this->containsKey(name)==false){

        throw std::invalid_argument("PlayList is not present");


    }
}


Song PlayListMap::playNext(std::string name) {
    if(this->containsKey(name)==true) {
        LinkedNode<List> *temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->getItem()->getName() == name) {
                return temp->getItem()->playNextSong();
            } else {
                temp = temp->getNext();
            }
        }
        temp = nullptr;
    }
    else {


        throw std::invalid_argument("PlayList is not present");


    }
}



bool PlayListMap::containsKey(std::string name){

    LinkedNode<List>* temp=head;
    bool isKeyed;
    for(int i=0; i<size; i++){
        if(temp->getItem()->getName()==name) {
            isKeyed=true;
            i=size;
        }
        else{
            temp=temp->getNext();
            isKeyed=false;
        }
    }
    temp= nullptr;
    return isKeyed;
}


void PlayListMap::removePlayList(std::string name) {
    LinkedNode<List>* temp=head;
    int count=0;
    while(temp!= nullptr){
        if(temp->getItem()->getName()==name){
            temp= nullptr;
        }
        count +=1;
    }
    int i = 0;
    temp=head;
    while (temp != nullptr && i + 1 < count) {
        temp = temp->getNext();
        i += 1;
    }
    LinkedNode<List>* tempNode=temp->getNext();
    temp->setNext(temp->getNext()->getNext());
    size -= 1;
    delete tempNode;
    tempNode= nullptr;
}
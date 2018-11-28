#include <iostream>
#include <string>
#include "PlayList.h"
using namespace std;


Playlist::Playlist(std::string name){
    head= nullptr;
    end= nullptr;
    size=0;
    this->name=name;
    duration=0;

}


Playlist::~Playlist() {
}


void Playlist::addSongToEnd(Song songToAdd){
    LinkedNode<Song>* newNode=new LinkedNode<Song>();
    newNode->setItem(songToAdd);
    if(head== nullptr){
        head = newNode;
        end = newNode;
        size +=1;
    }

    else{
        end->setNext(newNode);
        end=newNode;
        size +=1;

    }
}


void Playlist::remove(Song songToRemove){
    LinkedNode<Song>* temp=head;
    int count=0;
    while(temp!= nullptr){
        if(temp->getItem().getTitle()==songToRemove.getTitle()){
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
    LinkedNode<Song>* tempNode=temp->getNext();
    temp->setNext(temp->getNext()->getNext());
    size -= 1;
    delete tempNode;
    tempNode= nullptr;

}


std::string Playlist::getName() {
    return name;
}


Song Playlist::getSong(std::string title) {
    LinkedNode<Song>* temp=head;
    for(int i=0; i<size; i++){
        if(temp->getItem().getTitle()==title){
            return temp->getItem();
        }
        temp=temp->getNext();
    }
}

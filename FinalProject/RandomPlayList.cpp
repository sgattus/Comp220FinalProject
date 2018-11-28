#include <iostream>
#include <string>
#include "RandomPlayList.h"
using namespace std;


RandomPlaylist::RandomPlaylist(std::string name, int duration){
    head= nullptr;
    end= nullptr;
    size=0;
    this->name=name;
    duration=0;

}

//
//RandomPlaylist::~RandomPlaylist() {
//}


void RandomPlaylist::addSongToEnd(Song songToAdd){
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


void RandomPlaylist::remove(Song songToRemove){
    LinkedNode<Song>* temp=head;
    int count=0;
    while(temp!= nullptr){
        if(temp->getItem().getTitle()==songToRemove.getTitle()){
            temp= nullptr;
        }
        else {
            count += 1;
            temp = temp->getNext();
        }
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


std::string RandomPlaylist::getName() {
    return name;
}


Song RandomPlaylist::getSong(std::string title) {
    LinkedNode<Song>* temp=head;
    for(int i=0; i<size; i++){
        if(temp->getItem().getTitle()==title){
            return temp->getItem();
        }
        temp=temp->getNext();
    }


}

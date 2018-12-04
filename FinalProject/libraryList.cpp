#include <iostream>
#include <string>
#include "libraryList.h"
using namespace std;


libraryList::libraryList(std::string name){
    head= nullptr;
    end= nullptr;
    size=0;
    this->name=name;
    duration=0;

}

libraryList::~libraryList() {
    if (this->head != nullptr){
        this->clearList();
    }
}


void libraryList::addSongToEnd(Song& songToAdd){
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


void libraryList::remove(Song songToRemove) {
    if(songToRemove.getTitle()==head->getItem()->getTitle()){
        LinkedNode<Song> *temp = head;
        head=head->getNext();
        delete temp;
        size -=1;
    }
    else {
        LinkedNode<Song> *temp = head;
        int count = 0;
        while (temp != nullptr) {
            count += 1;
            if (temp->getItem()->getTitle() == songToRemove.getTitle()) {

                temp = nullptr;
            } else {

                temp = temp->getNext();
            }
        }
        int i = 0;
        temp = head;
        while (temp != nullptr && i + 2 < count) {
            temp = temp->getNext();
            i += 1;
        }


        LinkedNode<Song> *tempNode = temp->getNext();
        temp->setNext(temp->getNext()->getNext());
        size -= 1;
        delete tempNode;
        tempNode = nullptr;
    }
}



std::string libraryList::getName() {
    return name;
}




Song libraryList::getSong(std::string title) {
    LinkedNode<Song> *temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->getItem()->getTitle() == title) {
            return *temp->getItem();
        }
        temp = temp->getNext();
    }

    throw std::invalid_argument("Song is not present");
}

//Committed out for testing purposes
std::string libraryList::display(){

}

/**
*calculate the duration of the playlist
*/
void libraryList::calcDuration(){
    int totalDuration=0;
    LinkedNode<Song>* temp=head;
    for (int i = 0; i < size; i++) {
        totalDuration = totalDuration + temp->getItem()->getDuration();
        temp = temp->getNext();
    }
    duration = totalDuration;
    temp = nullptr;
}

/**
*play next song, returning song info and removing it from playlist (playnext)
* Through exception if no more songs
**/
Song libraryList::playNextSong(){
    LinkedNode<Song>* temp= head;
    Song* song=temp->getItem();
    head=head->getNext();
    size -=1;
    delete temp;
    return *song;

}



/**
* •	check if empty
* return true if empty
*/
bool libraryList::isEmpty(){
    if (size == 0){
        return true;
    }
    else{
        return false;
    }
}
void libraryList::clearList(){
    while (isEmpty() == false){
        this->remove(*head->getItem());
    }
    head = nullptr;
    end = nullptr;
}

int libraryList::getDuration() {
    return duration;
}




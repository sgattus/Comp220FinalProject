#include "PlayListMap.h"
#include <iostream>
#include <string>


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
    if(name==head->getItem()->getName()){
        LinkedNode<List> *temp = head;
        head=head->getNext();
        delete temp;
        size -=1;
    }
    else {
        LinkedNode<List> *temp = head;
        int count = 0;
        while (temp != nullptr) {
            count += 1;
            if (temp->getItem()->getName() == name) {

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


        LinkedNode<List> *tempNode = temp->getNext();
        if(end==tempNode){

            end= temp;

        }
        temp->setNext(temp->getNext()->getNext());
        size -= 1;

        delete tempNode;
        tempNode = nullptr;
    }
}

std::string PlayListMap::display(){
    LinkedNode<List>* temp=head;
    std::string playLists;
    while(temp!= nullptr){
        temp->getItem()->calcDuration();
        playLists=playLists+temp->getItem()->getName() + ", " + std::to_string(temp->getItem()->getDuration())+ "; ";
        temp=temp->getNext();
    }
    temp= nullptr;

    return playLists;

}

void PlayListMap::goThrough(std::string name) {
    LinkedNode<List>* tempList=head;
    while(tempList!= nullptr){
        tempList->getItem()->goThroughList(name);
        tempList=tempList->getNext();

    }
}

void PlayListMap::savePlaylist() {
    LinkedNode<List>* temp=head;

    ofstream outf("Playlist.dat");

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        cerr << "Uh oh, Music.dat could not be opened for writing!" << endl;
        exit(1);
    }
    while(temp!= nullptr){



        // We'll write two lines into this file
        outf << temp->getItem()->getName() << endl;
        temp->getItem()->saveSongs(temp->getItem()->getName());
        temp=temp->getNext();



    }
}
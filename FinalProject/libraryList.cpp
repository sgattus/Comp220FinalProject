#include <iostream>
#include <string>
#include "libraryList.h"
#include<stdio.h>
#include<string.h>
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

//copy constructor
libraryList::libraryList(const libraryList& libraryListToCopy){
    LinkedNode<Song>* newNode = libraryListToCopy.head;
    size = 0;
    head = nullptr;
    end = nullptr;
    while(newNode!= nullptr){
        Song* newSong = (newNode->getItem());
        this->addSongToEnd(*newSong);
        newNode = newNode->getNext();
    }

    delete newNode;
    newNode= nullptr;
}

//assignment operator
libraryList& libraryList::operator=(const libraryList& libraryListToCopy) {
    if(this!= &libraryListToCopy){
        while(head!= nullptr){
            LinkedNode<Song>* tempNode= head;
            head = head->getNext();
            size--;
            delete tempNode;
        }
        size = 0;
        head= nullptr;
        end= nullptr;

        LinkedNode<Song>* tempNode=libraryListToCopy.head;
        while(tempNode!= nullptr){
            Song* newSong = (tempNode->getItem());
            this->addSongToEnd(*newSong);
            tempNode = tempNode->getNext();
        }

        delete tempNode;
        tempNode= nullptr;
    }
    return* this;
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


        if(temp->getNext()==end){
            LinkedNode<Song> *tempNode = temp->getNext();
            temp->setNext(nullptr);
            end=temp;
            delete tempNode;
            tempNode= nullptr;
            size -=1;

        }
        else {
            LinkedNode<Song> *tempNode = temp->getNext();
            temp->setNext(temp->getNext()->getNext());

            size -= 1;
            delete tempNode;
            tempNode = nullptr;
        }
    }
}







Song* libraryList::getSong(std::string title, std::string artist) {
    LinkedNode<Song> *temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->getItem()->getTitle() == title && temp->getItem()->getArtist()==artist) {
            return temp->getItem();
        }
        temp = temp->getNext();
    }

    throw std::invalid_argument("Song is not present");
}

//I know it is not efficient but it works, would have gone back and fixed if I had more time
std::string libraryList::display(){

        //iterate through Linked Library Map
        LinkedNode<Song>* temp=head;
        //art holds char array of Artist, t is temp array for alphabetizing artist
        char art[size][20], t[20];
        //i, j are iterators
        int i, j;
        //go through map to add artist to array
        for(i=0; i<size; i++)
        {
            strcpy(art[i], temp->getItem()->getArtist().c_str());

            temp=temp->getNext();
        }
        //sort artist into temp array and back to artist array for alphabetizing
        for(i=1; i<size; i++)
        {
            for(j=1; j<size; j++)
            {
                if(strcmp(art[j-1], art[j])>0)
                {
                    strcpy(t, art[j-1]);
                    strcpy(art[j-1], art[j]);
                    strcpy(art[j], t);
                }
            }
        }
        //store songs into string to display
        std::string songs;
        // string to hold the artistBefore in the art array so we can make sure we are not repeating artist when adding to songs string
        std::string artistBefore;
        //num is just so I can say ARTIST(num) when displaying; clears things up
        int num=0;
        //go through art array to place songs after corresponding artist in alphabetical order
        for(i=0; i<size; i++)
        {
            num++;
            //check if artist is in art array twice, if so do not print
            if(art[i]==artistBefore){
                artistBefore=art[i];
                num -=1;
            }
            else {
                // Create char array for songs
                char song[size][20], t1[20];
                //count for song array
                int count = 0;
                //iterate through Map
                temp = head;
                //Add Artist to display string
                songs = songs + "ARTIST" + std::to_string(num) + ": " + art[i] + ": ";
                // go through Map to get songs from specific artist
                for (int p = 0; p < size; p++) {
                    //Check if song is from specific artist
                    if (temp->getItem()->getArtist() == art[i]) {
                        //if so add to song array
                        strcpy(song[count], temp->getItem()->getTitle().c_str());
                        count += 1;
                    }
                    temp = temp->getNext();
                }
                //alphabetize song array for given artist
                for (int l = 1; l < count; l++) {
                    for (j = 1; j < count; j++) {
                        if (strcmp(song[j - 1], song[j]) > 0) {
                            strcpy(t1, song[j - 1]);
                            strcpy(song[j - 1], song[j]);
                            strcpy(song[j], t1);
                        }
                    }
                }
                // add songs to display string
                for (int b = 0; b < count; b++) {

                    //if last song do not add a comma at the end
                    if(i==size-1 && b==count-1){
                        songs=songs+song[b];
                    }
                    else{
                        songs = songs + song[b] + ", ";
                    }
                }
                //check if duplicate artist is in artist array
                artistBefore = art[i];
            }

        }
        return songs;

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


int genRandInt(int min, int max){
    if (min>max) {
        int newMin = max;
        int newMax = min;
        min = newMin;
        max = newMax;
    }
    int randInt= rand()%(max-min+1)+min;
    return randInt;
}

Song libraryList::randomSong(){
    int nodeNum= genRandInt(1, size);
    LinkedNode<Song>* temp= head;
    for (int i=1; i<nodeNum; i++){
        temp=temp->getNext();
    }

    return *temp->getItem();
}



void libraryList::goThroughList(std::string name, std::string artist){
    LinkedNode<Song>* temp=head;
    while(temp!= nullptr){
        if(temp->getItem()->getTitle()==name && temp->getItem()->getArtist()==artist){
            this->remove(*temp->getItem());
            temp= nullptr;
        }
        else{
            temp=temp->getNext();
        }
    }

}

std::string libraryList::displayArtist(std::string artist) {
    LinkedNode<Song>* temp=head;
    std::string artistList=artist+ ": ";
    while(temp!= nullptr){
        if(temp!= nullptr){
            if(temp->getItem()->getArtist()==artist){
                artistList=artistList+temp->getItem()->getTitle()+", ";
            }
            temp=temp->getNext();
        }
    }

    return artistList;

}

void libraryList::saveSongs(){
    LinkedNode<Song>* temp=head;
    ofstream outf("library.dat");

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        cerr << "Uh oh, Music.dat could not be opened for writing!" << endl;
        exit(1);
    }
    while(temp!= nullptr){




        // We'll write two lines into this file
        outf << temp->getItem()->getArtist() << endl;
        outf << temp->getItem()->getTitle() << endl;
        outf << std::to_string(temp->getItem()->getDuration()) << endl;
        outf << std::to_string(temp->getItem()->getPlayCount()) << endl;
        temp=temp->getNext();


    }
}




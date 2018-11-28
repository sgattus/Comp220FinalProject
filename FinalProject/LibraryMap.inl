#include "LibraryMap.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Constructor
 */
template <class T>
LibraryMap<T>::LibraryMap(){
    head= nullptr;
    end= nullptr;
    //help search through LinkedListMap
    size=0;
}

template <class T>
void LibraryMap<T>::put(T& value){
    LinkedNode<T>* newNode=new LinkedNode<T>();
    newNode->setItem(value);
    if(head== nullptr){
        head = newNode;
        end = newNode;
        size +=1;
    }
    else if(this->containsKey(value.getTitle())==true){
        LinkedNode<T>* temp=head;
        for(int i=0; i<size; i++){
            if(temp->getItem().getTitle()==value.getTitle()) {
                temp->setItem(value);
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

template <class T>
T LibraryMap<T>::get(std::string songName){
    LinkedNode<T> *temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->getItem().getTitle()==songName) {
            return temp->getItem();
        } else {
            temp = temp->getNext();
        }
    }
    temp = nullptr;
    //} else {
    if(this->containsKey(songName)==false){

        throw std::invalid_argument("Song is not present");


    }
}

template <class T>
bool LibraryMap<T>::containsKey(std::string songName){

    LinkedNode<T>* temp=head;
    bool isKeyed;
    for(int i=0; i<size; i++){
        if(temp->getItem().getTitle()==songName) {
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

template <class T>
std::string LibraryMap<T>::display() {
    //iterate through Linked Library Map
    LinkedNode<T>* temp=head;
    //art holds char array of Artist, t is temp array for alphabetizing artist
    char art[size][20], t[20];
    //i, j are iterators
    int i, j;
    //go through map to add artist to array
    for(i=0; i<size; i++)
    {
        strcpy(art[i], temp->getItem().getArtist().c_str());

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
                if (temp->getItem().getArtist() == art[i]) {
                    //if so add to song array
                    strcpy(song[count], temp->getItem().getTitle().c_str());
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

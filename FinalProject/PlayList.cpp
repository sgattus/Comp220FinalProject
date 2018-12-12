#include <iostream>
#include <string>
#include "PlayList.h"

Playlist::Playlist(std::string name){
    head= nullptr;
    end= nullptr;
    size=0;
    this->name=name;
    duration=0;

}

//copy constructor
Playlist::Playlist(const Playlist& LinkedListMapToCopy){
    LinkedNode<Song>* newNode = LinkedListMapToCopy.head;
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
Playlist& Playlist::operator=(const Playlist & LinkedListMapToCopy) {
    if(this!= &LinkedListMapToCopy){
        while(head!= nullptr){
            LinkedNode<Song>* tempNode= head;
            head = head->getNext();
            size--;
            delete tempNode;
        }
        size = 0;
        head= nullptr;
        end= nullptr;

        LinkedNode<Song>* tempNode=LinkedListMapToCopy.head;
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


//destructor
Playlist::~Playlist() {
    if (this->head != nullptr){
        this->clearList();
    }
}

void Playlist::addSongToEnd(Song& songToAdd){
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


void Playlist::remove(Song songToRemove) {
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



std::string Playlist::getName() {
    return name;
}




Song Playlist::getSong(std::string title) {
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
std::string Playlist::display(){
    LinkedNode<Song>* temp=head;
    std::string playlistString="";
    while (temp->getNext()!= nullptr){
        std::string artist= temp->getItem()->getArtist();
        std::string title= temp->getItem()->getTitle();
        std::string duration= std::to_string(temp->getItem()->getDuration());
        playlistString+=title+" by "+artist+"(duration of "+duration+" seconds), ";
        temp=temp->getNext();
    }
    //last node in the list(it will have a next of nullptr so the while loop won't cover it
    std::string artist= temp->getItem()->getArtist();
    std::string title= temp->getItem()->getTitle();
    std::string duration= std::to_string(temp->getItem()->getDuration());
    playlistString+=title+" by "+artist+"(duration of "+duration+" seconds)";

    temp=nullptr;

    return playlistString;

}

/**
*calculate the duration of the playlist
*/
void Playlist::calcDuration(){
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
Song Playlist::playNextSong(){
    LinkedNode<Song>* temp= head;
    Song* song=temp->getItem();
    head=head->getNext();
    size -=1;
    if(head== nullptr){
        end= nullptr;
    }
    delete temp;
    return *song;

}



/**
* •	check if empty
* return true if empty
*/
bool Playlist::isEmpty(){
    if (size == 0){
        return true;
    }
    else{
        return false;
    }
}
void Playlist::clearList(){
    while (isEmpty() == false){
        this->remove(*head->getItem());
    }
    head = nullptr;
    end = nullptr;
}

int Playlist::getDuration() {
    return duration;
}

int Playlist::fillRP(List* p, int maxDuration, Song& songToAdd, int tries){

}

Song Playlist::randomSong(){

}

void Playlist::goThroughList(std::string name){
    LinkedNode<Song>* temp=head;
    while(temp!= nullptr){
        if(temp->getItem()->getTitle()==name){
            this->remove(*temp->getItem());
            temp= nullptr;
        }
        else{
            temp=temp->getNext();
        }
    }
}

void Playlist::saveSongs(std::string fileName) {
    LinkedNode<Song>* temp=head;
    ofstream outf(fileName +".dat");

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
        temp=temp->getNext();


    }
}



#include <iostream>
#include <string>
#include "RandomPlayList.h"
using namespace std;

RandomPlaylist::RandomPlaylist(std::string name, int duration){
    head= nullptr;
    end= nullptr;
    this->name=name;
    this->duration=0;
    size=0;

}


RandomPlaylist::RandomPlaylist(const RandomPlaylist& playlistToCopy) {
    if (playlistToCopy.head == nullptr) {
        head = nullptr;
        end = nullptr;
        size = playlistToCopy.size;
        this->name = playlistToCopy.name;
        duration = 0;
    }
    else {
        LinkedNode<Song> *temp = playlistToCopy.head;
        Song s1 = Song(playlistToCopy.head->getItem()->getArtist(), playlistToCopy.head->getItem()->getTitle(), playlistToCopy.head->getItem()->getDuration());
        LinkedNode<Song> *first = new LinkedNode<Song>;
        head = first;

        if (temp->getNext() != nullptr) {
            while (temp->getNext() != nullptr) {
                head->getNext();
                Song nextSong = Song(playlistToCopy.head->getItem()->getArtist(), playlistToCopy.head->getItem()->getTitle(), playlistToCopy.head->getItem()->getDuration());
                LinkedNode<Song> *newNode = new LinkedNode<Song>;
                first->setNext(newNode);
                temp=temp->getNext();
                first=first->getNext();
                newNode= nullptr;
            }

            head->getNext();
            Song nextSong = Song(playlistToCopy.head->getItem()->getArtist(), playlistToCopy.head->getItem()->getTitle(), playlistToCopy.head->getItem()->getDuration());
            LinkedNode<Song> *newNode = new LinkedNode<Song>;
            first->setNext(newNode);
            temp= nullptr;
            first= first->getNext();
            end=first;
            this->name = playlistToCopy.name;
            duration = 0;
            first= nullptr;
            newNode= nullptr;
        }


    }


}


RandomPlaylist& RandomPlaylist::operator=(const RandomPlaylist& playlistToCopy){
    if(&playlistToCopy==this){
        return *this;
    }
    else{
        if (playlistToCopy.head == nullptr) {
            head = nullptr;
            end = nullptr;
            size = 0;
            this->name = playlistToCopy.name;
            duration = playlistToCopy.size;
            size=playlistToCopy.size;
        }
        else {
            LinkedNode<Song> *temp = playlistToCopy.head;
            Song s1 = Song(playlistToCopy.head->getItem()->getArtist(), playlistToCopy.head->getItem()->getTitle(), playlistToCopy.head->getItem()->getDuration());
            LinkedNode<Song> *first = new LinkedNode<Song>;
            head = first;

            if (temp->getNext() != nullptr) {
                while (temp->getNext() != nullptr) {
                    head->getNext();
                    Song nextSong = Song(playlistToCopy.head->getItem()->getArtist(), playlistToCopy.head->getItem()->getTitle(), playlistToCopy.head->getItem()->getDuration());
                    LinkedNode<Song> *newNode = new LinkedNode<Song>;
                    first->setNext(newNode);
                    temp=temp->getNext();
                    first=first->getNext();
                    newNode= nullptr;

                }
                head->getNext();
                Song nextSong = Song(playlistToCopy.head->getItem()->getArtist(), playlistToCopy.head->getItem()->getTitle(), playlistToCopy.head->getItem()->getDuration());
                LinkedNode<Song> *newNode = new LinkedNode<Song>;
                first->setNext(newNode);
                temp= nullptr;
                first= first->getNext();
                end=first;
                this->name = playlistToCopy.name;
                duration = 0;
                first= nullptr;
                newNode= nullptr;
            }



            LinkedNode<Song>* currNode= head;
            LinkedNode<Song>* nextNode= head;
            head= nullptr;
            if (isEmpty()){
                currNode= nullptr;
                nextNode= nullptr;
            }
            else{
                while (currNode->getNext() != end) {
                    nextNode = nextNode->getNext();
                    delete currNode;
                    currNode = nextNode;
                }
                delete currNode;
                currNode = nullptr;
                nextNode = nullptr;
                end= nullptr;
            }


        }
        return *this;
    }
}


RandomPlaylist::~RandomPlaylist() {
    LinkedNode<Song>* currNode= head;
    LinkedNode<Song>* nextNode= head;
    head= nullptr;
    if (isEmpty()){
        currNode= nullptr;
        nextNode= nullptr;
    }
    else{
        while (currNode->getNext() != end) {
            nextNode = nextNode->getNext();
            delete currNode;
            currNode = nextNode;
        }
        delete currNode;
        currNode = nullptr;
        nextNode = nullptr;
        end= nullptr;
    }
    size=0;

}


void RandomPlaylist::addSongToEnd(Song& songToAdd){
    LinkedNode<Song>* newNode=new LinkedNode<Song>();
    newNode->setItem(songToAdd);
    if(head== nullptr){
        head = newNode;
        end = newNode;
        size +=1;
    }
    else if(head==end){
        end=newNode;
        head->setNext(end);
    }

    else{
        end->setNext(newNode);
        end=newNode;
        size +=1;
    }
}


void RandomPlaylist::remove(Song songToRemove) {
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



std::string RandomPlaylist::getName() {
    return name;
}

int RandomPlaylist::getDuration(){
    return duration;
}


Song RandomPlaylist::getSong(std::string title) {
    LinkedNode<Song> *temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->getItem()->getTitle() == title) {
            return *temp->getItem();
        }
        temp = temp->getNext();
    }

    throw std::invalid_argument("Song is not present");
}


void RandomPlaylist::calcDuration(){
    LinkedNode<Song>* temp= head;
    duration=0;
    if(head== nullptr){
        duration=0;
    }
    else {
        while (temp->getNext() != nullptr) {
            duration += temp->getItem()->getDuration();
            temp = temp->getNext();
        }
        duration += temp->getItem()->getDuration();
    }
    temp= nullptr;
}

bool RandomPlaylist::isEmpty(){
    if (head== nullptr && end==nullptr){
        return true;
    }
    return false;

}

Song RandomPlaylist::playNextSong(){
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


std::string RandomPlaylist::display(){
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


int RandomPlaylist::fillRP(List* p, int maxDuration, Song& songToAdd, int tries){

    //turns song into node
    LinkedNode<Song>* newNode= new LinkedNode<Song>();
    newNode->setItem(songToAdd);


    //checks that it won't go over the maxDuration
    if(songToAdd.getDuration()+duration>maxDuration){
        return tries+1;

    }
    else {
        //0 nodes
        if (isEmpty()) {
            addSongToEnd(songToAdd);
        }

            //1 node or more should work for this
        else {
            //checks all the songs in the playlist to make sure that it isn't a repeated song
            LinkedNode<Song> *temp = head;
            while (temp->getNext() != nullptr && temp != newNode) {
                temp = temp->getNext();
            }

            //checks last node and adds it if needed. If temp.getNext()!= nullptr that means that
            //there is a repeat in the song. The loop terminates when either temp reaches the end
            //or if the song is found and is already in the list
            if (temp->getNext() == nullptr && temp != newNode) {
                addSongToEnd(songToAdd);
            }
            temp = nullptr;
            return tries;
        }
        return tries;
    }

    newNode= nullptr;
}

void RandomPlaylist::clearList(){

}

void RandomPlaylist::goThroughList(std::string name){
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

void RandomPlaylist::saveSongs(std::string fileName) {
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
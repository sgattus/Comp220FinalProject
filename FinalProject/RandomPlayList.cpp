#include <iostream>
#include <string>
#include "RandomPlayList.h"
using namespace std;


RandomPlaylist::RandomPlaylist(std::string name, int duration){
    head= nullptr;
    end= nullptr;
    this->name=name;

    Song s1 = Song("Lady Gaga", "Poker Face", 200);
    LinkedNode<Song> *newNode = new LinkedNode<Song>;
    newNode->setItem(s1);
    head= newNode;
    end=newNode;

    Song s2 = Song("Sia", "Chandelier", 200);
    LinkedNode<Song> *newNode2 = new LinkedNode<Song>;
    newNode->setItem(s2);
    head->setNext(newNode2);
    end=newNode2;

    Song s3 = Song("Kelsey-Ryan Elizabeth-Lily Grant", "i was born in a tree", 500);
    addSongToEnd(s3);

    Song s4 = Song("Sonart Robitussin Guhtaytus", "it's been a coon's age", 50);
    addSongToEnd(s4);

    Song s5 = Song("Katherine Louise Polley", "EP: drownin in pussy", 1000);
    addSongToEnd(s5);

    Song s6 = Song("Kerry Anne Buckman", "Lullaby #5", 5);
    addSongToEnd(s6);

    duration=1955;

    size=6;
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
        Song s1 = Song(playlistToCopy.head->getItem().getArtist(), playlistToCopy.head->getItem().getTitle(), playlistToCopy.head->getItem().getDuration());
        LinkedNode<Song> *first = new LinkedNode<Song>;
        head = first;

        if (temp->getNext() != nullptr) {
            while (temp->getNext() != nullptr) {
                head->getNext();
                Song nextSong = Song(playlistToCopy.head->getItem().getArtist(), playlistToCopy.head->getItem().getTitle(), playlistToCopy.head->getItem().getDuration());
                LinkedNode<Song> *newNode = new LinkedNode<Song>;
                first->setNext(newNode);
                temp=temp->getNext();
                first=first->getNext();
                newNode= nullptr;
            }

            head->getNext();
            Song nextSong = Song(playlistToCopy.head->getItem().getArtist(), playlistToCopy.head->getItem().getTitle(), playlistToCopy.head->getItem().getDuration());
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
            Song s1 = Song(playlistToCopy.head->getItem().getArtist(), playlistToCopy.head->getItem().getTitle(), playlistToCopy.head->getItem().getDuration());
            LinkedNode<Song> *first = new LinkedNode<Song>;
            head = first;

            if (temp->getNext() != nullptr) {
                while (temp->getNext() != nullptr) {
                    head->getNext();
                    Song nextSong = Song(playlistToCopy.head->getItem().getArtist(), playlistToCopy.head->getItem().getTitle(), playlistToCopy.head->getItem().getDuration());
                    LinkedNode<Song> *newNode = new LinkedNode<Song>;
                    first->setNext(newNode);
                    temp=temp->getNext();
                    first=first->getNext();
                    newNode= nullptr;

                }
                head->getNext();
                Song nextSong = Song(playlistToCopy.head->getItem().getArtist(), playlistToCopy.head->getItem().getTitle(), playlistToCopy.head->getItem().getDuration());
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


void Playlist::remove(Song songToRemove) {
    if(songToRemove.getTitle()==head->getItem().getTitle()){
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
            if (temp->getItem().getTitle() == songToRemove.getTitle()) {

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
    LinkedNode<Song>* temp=head;
    for(int i=0; i<size; i++){
        if(temp->getItem().getTitle()==title){
            return temp->getItem();
        }
        temp=temp->getNext();
    }
    return temp->getItem();


}

void RandomPlaylist::calcDuration(){
    LinkedNode<Song>* temp= head;
    duration=0;
    if(head== nullptr){
        duration=0;
    }
    else {
        while (temp->getNext() != nullptr) {
            duration += temp->getItem().getDuration();
            temp = temp->getNext();
        }
        duration += temp->getItem().getDuration();
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
    Song ret= temp->getItem();
    head=head->getNext();
    delete temp;
    temp=nullptr;
    size=size-1;
    return ret;
}


std::string display(){
    return "hi";
}
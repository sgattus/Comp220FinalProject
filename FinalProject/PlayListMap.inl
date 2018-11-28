#include "LibraryMap.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * Constructor
 */
template <class T>
PlayListMap<T>::PlayListMap() {
    head= nullptr;
    end= nullptr;
    this->libray= nullptr;
    size=0;
}

template <class T>
void PlayListMap<T>::put(Playlist& value){
    LinkedNode<Playlist>* newNode=new LinkedNode<Playlist>();
    newNode->setItem(value);
    if(head== nullptr){
        head = newNode;
        end = newNode;
        size +=1;
    }
    else if(this->containsKey(value.getName())==true){
        LinkedNode<Playlist>* temp=head;
        for(int i=0; i<size; i++){
            if(temp->getItem().getName()==value.getName()) {
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
void PlayListMap<T>::setLibrary(LibraryMap<Song> lib){
    this->libray=new LibraryMap<Song>(lib);
}


/**
    *remove the given song from given playlist
   * Use this.get to find playlist
   *
   *Use playlist remove song from given playlist
   */
template <class T>
void PlayListMap<T>::remove(std::string name, std::string artist, std::string title){
    if(this->containsKey(name)==true){
        if(libray->containsKey(title)==true){
            this->get(name).remove(libray->get(title));
        }
        else{
            //change to exception
            cout<<"song not in library"<<endl;
        }

    }
    else{
        //change to exception
        cout<<"playlist does not exsist"<<endl;
    }

}

template <class T>
void PlayListMap<T>::add(Song song,std::string name){
    this->get(name).addSongToEnd(song);

}

template <class T>
Playlist PlayListMap<T>::get(std::string name){
    LinkedNode<Playlist> *temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->getItem().getName()==name) {
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

template <class T>
bool PlayListMap<T>::containsKey(std::string name){

    LinkedNode<T>* temp=head;
    bool isKeyed;
    for(int i=0; i<size; i++){
        if(temp->getItem().getName()==name) {
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
void PlayListMap<T>::removePlayList(std::string name) {
    LinkedNode<T>* temp=head;
    int count=0;
    while(temp!= nullptr){
        if(temp->getItem().getName()==name){
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
    LinkedNode<T> tempNode=temp->getNext();
    temp->setNext(temp->getNext()->getNext());
    size -= 1;
    delete tempNode;
    tempNode= nullptr;
}
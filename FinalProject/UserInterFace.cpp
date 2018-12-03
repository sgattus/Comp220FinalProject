//
// Created by Sonya Gattus on 11/20/18.
//

#include<iostream>
#include<string.h>
#include<stdio.h>
#include "LibraryMap.h"
#include "Song.h"
#include "PlayListMap.h"
#include "UserInterFace.h"
#include "TestLib.h"
using namespace std;


UserInterFace::UserInterFace(PlayListMap<List>* listOfPlaylistIn){
    listOfPlaylist=listOfPlaylistIn;


}


std::string UserInterFace::displayLibrary(){
    return listOfPlaylist->getLibrary()->display();
}

void UserInterFace::neW(std::string name){
    List* playList= new Playlist(name);
    listOfPlaylist->put(*playList);

}

void  UserInterFace::add(std::string name, std::string artist, std::string title) {
    if(listOfPlaylist->getLibrary()->containsKey(title)==true){
        List* p1=listOfPlaylist->get(name);
        p1->addSongToEnd(*listOfPlaylist->getLibrary()->get(title));
        listOfPlaylist->put(*p1);
        cout<<"Added " + title + "to " + name+ " playlist"<<endl;
        cout<<"check " + listOfPlaylist->get(name)->getSong(title).getTitle()<<endl;
    }
    else{
        cout<<"Song is not in Library"<<endl;
    }
}

PlayListMap<List>* UserInterFace::getPlayList(){
    return listOfPlaylist;
}

void UserInterFace::playNext(std::string name, PlayListMap<List> map) {
 Song song= listOfPlaylist->playNext(name);
 cout<<song.getTitle()<<endl;
 //

}
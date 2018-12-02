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
        listOfPlaylist->get(name)->addSongToEnd(*listOfPlaylist->getLibrary()->get(title));
        cout<<"Added " + title + "to " + name+ " playlist"<<endl;
        cout<<"check " + listOfPlaylist->get(name)->getSong(title).getTitle()<<endl;
    }
    else{
        cout<<"Song is not in Library"<<endl;
    }
}

void UserInterFace::playNext(std::string name) {
    Song song=listOfPlaylist->get(name)->playNextSong();
    listOfPlaylist->getLibrary()->get(song.getTitle())->playSong();
    //figure out play count
   // cout<<song.getTitle() + " " + song.getArtist()+ " " + to_string(song.getDuration() + )<<endl;

}
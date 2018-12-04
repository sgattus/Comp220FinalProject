
#include<iostream>
#include<string>
#include "UI.h"



UserInterFace::UserInterFace(){
    listOfPlaylist= new PlayListMap();
    lib= new libraryList("Library");

    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);

    lib->addSongToEnd(song1);
    lib->addSongToEnd(song2);
    lib->addSongToEnd(song3);
    lib->addSongToEnd(song4);

    listOfPlaylist->put(*lib);



}

void UserInterFace::neW(std::string name){
    List* playlist= new Playlist(name);
    listOfPlaylist->put(*playlist);

}

void UserInterFace::add(std::string name, std::string artist, std::string title){
    if(lib->getSong(title).getTitle()==title){
        List* p1=listOfPlaylist->get(name);
        Song song=lib->getSong(title);
        p1->addSongToEnd(song);
        listOfPlaylist->put(*p1);
        std::cout<<"Added " + title + "to " + name+ " playlist"<<std::endl;
        std::cout<<"check " + listOfPlaylist->get(name)->getSong(title).getTitle()<<std::endl;

    }
    else{
        std::cout<<"Song is not in Library"<<std::endl;
    }
}

void UserInterFace::playNext(std::string name){
    Song song= listOfPlaylist->get(name)->playNextSong();
    std::cout<<song.getTitle() + " " + song.getArtist() + " " + std::to_string(song.getDuration())<<std::endl;




}

std::string UserInterFace::displayLibrary(){
    return "working";

}





int main()
{

    UserInterFace ui= UserInterFace();
    ui.neW("p1");
    ui.neW("p2");
    ui.add("p1","Genesis","That's All");
    ui.playNext("p1");
    std::cout<<ui.displayLibrary();

    std::cout<<"--testDone--"<<std::endl;




    return 0;

}



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
    Song song5 = Song("KerryAnne Buckman","Lullaby #5", 5);

    lib->addSongToEnd(song1);
    lib->addSongToEnd(song2);
    lib->addSongToEnd(song3);
    lib->addSongToEnd(song4);
    lib->addSongToEnd(song5);

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
    std::cout<<"Song Removed: " + song.getTitle() + " " + song.getArtist() + " " + std::to_string(song.getDuration())<<std::endl;




}

std::string UserInterFace::displayLibrary(){
    return lib->display();

}

void UserInterFace::neWRandomPlayList(){
    int tries=0;
    List* p1= new RandomPlaylist("My Faves", 100000);
    while(p1->getDuration()<700 && tries<3){
        Song songToAdd= lib->randomSong();
        std::cout<<"in loop"<<std::endl;
        tries=p1->fillRP(p1, 700, songToAdd, tries);
        p1->calcDuration();
    }

    std::cout<<"out of loop"<<std::endl;

    listOfPlaylist->put(*p1);

    std::string dispStr= p1->display();
    std::cout<<dispStr<<std::endl;


}

std::string UserInterFace::diplayPlaylist(std::string name){
    return listOfPlaylist->get(name)->display();
}





int main()
{
    srand(time(NULL));
    UserInterFace ui= UserInterFace();
    ui.neW("p1");
    ui.neW("p2");
    ui.add("p1","Genesis","That's All");
    ui.playNext("p1");
    std::cout<<ui.displayLibrary();
    ui.add("p1","Men At Work","Land Down Under");
    ui.add("p1","KerryAnne Buckman","Lullaby #5");
    ui.playNext("p1");
    ui.neWRandomPlayList();
    ui.playNext("My Faves");
    std::cout<<ui.diplayPlaylist("p1")<<std::endl;
    std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
    std::cout<<ui.displayLibrary()<<std::endl;




    std::cout<<"--testDone--"<<std::endl;




    return 0;

}


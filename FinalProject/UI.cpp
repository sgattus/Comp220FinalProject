
#include<iostream>
#include<string>
#include "UI.h"
#include "TestLib.h"
#include <sstream>
using namespace std;




UserInterFace::UserInterFace(){
    listOfPlaylist= new PlayListMap();
    lib= new libraryList("Library");

    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);
    Song song5 = Song("KerryAnne Buckman","Lullaby #5", 5);
    Song song6 = Song("Kelsey Grant","I Was Born In A Tree",7);
    Song song7 = Song("Ween", "It's Gonna Be Alright Baby",9);

    lib->addSongToEnd(song1);
    lib->addSongToEnd(song2);
    lib->addSongToEnd(song3);
    lib->addSongToEnd(song4);
    lib->addSongToEnd(song5);
    lib->addSongToEnd(song6);
    lib->addSongToEnd(song7);





}

void UserInterFace::neW(std::string name){
    std::cout<<"Make New Playlist\n";
    List* playlist= new Playlist(name);
    listOfPlaylist->put(*playlist);
    std::cout<<"New Playlist made: " + name + "\n";

}

void UserInterFace::add(std::string name, std::string artist, std::string title){
    std::cout<<"Add Song To Playlist\n";
//    if(lib->getSong(title).getTitle()==title){
//        List* p1=listOfPlaylist->get(name);
//        Song song=lib->getSong(title);
//        p1->addSongToEnd(song);
//        listOfPlaylist->put(*p1);
//        std::cout<<"Added " + title + "to " + name+ " playlist"<<std::endl;
//        //std::cout<<"check " + listOfPlaylist->get(name)->getSong(title).getTitle()<<std::endl;
//
//    }
//    else{
//        std::cout<<"Song is not in Library"<<std::endl;
//    }


    try {
        listOfPlaylist->get(name);
        List* p1=listOfPlaylist->get(name);
        Song song=lib->getSong(title);
        p1->addSongToEnd(song);
        listOfPlaylist->put(*p1);
        std::cout<<"Added " + title + "to " + name+ " playlist"<<std::endl;

    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("Song is not in Library");
        std::cout<<"Song is not in Library, can't add :( \n";

    }
}

void UserInterFace::playNext(std::string name){
    std::cout<<"Play Next Song in Playlist\n";
    Song song= listOfPlaylist->get(name)->playNextSong();
    std::cout<<"Song Removed: " + song.getTitle() + " " + song.getArtist() + " " + std::to_string(song.getDuration())<<std::endl;
    if(listOfPlaylist->get(name)->isEmpty()==true){
        listOfPlaylist->removePlayList(name);
        std::cout<<"Playlist " + name + " is removed!"<<std::endl;
    }



}

std::string UserInterFace::displayLibrary(){
    std::cout<<"Display Library\n";
    return lib->display();

}

void UserInterFace::neWRandomPlayList(std::string name){
    std::cout<<"Make New Random Playlist\n";

    int tries=0;
    List* p1= new RandomPlaylist(name, 100000);
    while(p1->getDuration()<700 && tries<3){
        Song songToAdd= lib->randomSong();
        //std::cout<<"in loop"<<std::endl;
        tries=p1->fillRP(p1, 700, songToAdd, tries);
        p1->calcDuration();
    }

//    std::cout<<"out of loop"<<std::endl;

    listOfPlaylist->put(*p1);
    std::cout<<"New Random Playlist made: " + name + "\n";


//    std::string dispStr= p1->display();
//    std::cout<<dispStr<<std::endl;


}

std::string UserInterFace::diplayPlaylist(std::string name){
    std::cout<<"Display Playlist\n";

    try {
        listOfPlaylist->get(name);
        return name + ": "+ listOfPlaylist->get(name)->display();

    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        return "Sorry Playlist does not exsist";
    }


}

std::string UserInterFace::displayAllPlaylist(){
    std::cout<<"Display All Playlist\n";
    return listOfPlaylist->display();
}

void UserInterFace::addSongToLibrary(std::string artist, std::string song, int duration){
    std::cout<<"Add Song to Library\n";
    Song newSong = Song(artist, song,duration);

    lib->addSongToEnd(newSong);
    Song testSong=lib->getSong(song);
    std::cout<<"Added " + testSong.getTitle() + " by "+ testSong.getArtist() + " with a duration of "+ std::to_string(testSong.getDuration()) + " to library\n";
}

std::string UserInterFace::removeSong(std::string name){
    std::cout<<"Remove Song\n";

    try {
        lib->getSong(name).getTitle();
        Song song = lib->getSong(name);
        lib->goThroughList(name);

        listOfPlaylist->goThrough(name);
        return "Song Removed: " + song.getTitle() + ", " + song.getArtist() + ", " + std::to_string(song.getDuration());

    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("Song is not in Library");
        return "Song is not in Library";
    }


}





int main()
{
    srand(time(NULL));
    UserInterFace ui= UserInterFace();
    ui.neW("p1");
    ui.neWRandomPlayList("Pump Up Jams");
    std::cout<<ui.diplayPlaylist("Pump Up Jams") + "\n";
    ui.playNext("Pump Up Jams");
    ui.playNext("Pump Up Jams");
    ui.neW("p2");
    ui.add("p2","Genesis","That's All");
    ui.add("p1","Genesis","That's All");
    ui.playNext("p2");
    std::cout<<ui.displayLibrary();
    ui.add("p1","Men At Work","Land Down Under");
    ui.add("p1","Ween", "It's Gonna Be Alright Baby");
    ui.add("p1","KerryAnne Buckman","Lullaby #5");
    ui.add("p1","Kelsey Grant","I Was Born In A Tree");
    ui.playNext("p1");
    ui.neWRandomPlayList("My Faves");
    ui.playNext("My Faves");
    std::cout<<ui.diplayPlaylist("p1")<<std::endl;
    std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
    std::cout<<ui.displayLibrary()<<std::endl;
    std::cout<<ui.displayAllPlaylist()<<std::endl;
    ui.playNext("p1");
    std::cout<<ui.displayLibrary()<<std::endl;
    std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
    std::cout<<ui.diplayPlaylist("p1")<<std::endl;
    std::cout<<ui.removeSong("Lullaby #5")<<std::endl;
    std::cout<<ui.diplayPlaylist("p1")<<std::endl;
    std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
    std::cout<<ui.displayLibrary()<<std::endl;




    std::cout<<"--testDone--"<<std::endl;
    std::string choice;
    while(choice!="12"){
        std::cout<<"Welcome, Please press corresponding number with choice listed"<<std::endl;
        std::cout<<"1) HELP\n 2)Display Library\n 3)Display Playlist\n 4)Remove Song From Everything\n 5)Add Song From Library to Playlist\n 6)Add Song to Library\n 7)Play Next Song in Playlist\n 8)Display All Playlist\n 12)QUIT\n";
        std::cout<<"Please Enter Choice: ";
        std::getline(std::cin,choice);
        if(choice=="1"){
            std::cout<<"Not implemented yet, sorry :(\n";

        }
        else if(choice=="2"){
            std::cout<<ui.displayLibrary() + "\n";
        }
        else if(choice=="3"){
            std::cout<<"Please enter Playlist name: ";
            std::string playlist;
            std::getline(std::cin,playlist);
            std::cout<<ui.diplayPlaylist(playlist) + "\n";

        }
        else if(choice=="4"){
            std::cout<<"Please enter song to remove from Playlist(s) and library: \n";
            std::string song;
            std::getline(std::cin,song);
            std::cout<<ui.removeSong(song) + "\n";
        }

        else if(choice=="5"){
            std::cout<<"Please enter Playlist, Song to add, and Artitst \n";
            std::string song;
            std::string playlist;
            std::string artist;
            std::cout<<"Please Enter Song: \n";
            std::getline(std::cin,song);
            std::cout<<"Please Enter Artitst: \n";
            std::getline(std::cin,artist);
            std::cout<<"Please Enter Playlist: \n";
            std::getline(std::cin,playlist);
            ui.add(playlist,artist,song);
        }

        else if(choice=="6"){
            std::cout<<"Please enter Song to add, Artitst, and Duration \n";
            std::string song;
            std::string duration;
            std::string artist;
            std::cout<<"Please Enter Song: \n";
            std::getline(std::cin,song);
            std::cout<<"Please Enter Artitst: \n";
            std::getline(std::cin,artist);
            std::cout<<"Please Enter Playlist: \n";
            std::getline(std::cin,duration);
            std::stringstream geek(duration);
            int x=0;
            geek>>x;
            ui.addSongToLibrary(artist,song,x);

        }

        else if(choice=="7") {
            std::cout << "Please enter Playlist name: ";
            std::string playlist;
            std::getline(std::cin, playlist);
            ui.playNext(playlist);
        }

        else if(choice=="8"){
            std::cout<<ui.displayAllPlaylist() + "\n";
        }

    }




    return 0;

}



#include<iostream>
#include<string>
#include "UI.h"
#include "TestLib.h"
#include <sstream>
#include <fstream>
#include <cstdlib> // for exit()
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

    try {
        listOfPlaylist->get(name);
        List* p1=listOfPlaylist->get(name);
        Song* song=lib->getSong(title);
        p1->addSongToEnd(*song);
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
    if(listOfPlaylist->get(name)->isEmpty()==true){
        listOfPlaylist->removePlayList(name);
        std::cout << "Playlist " + name + " is removed!" << std::endl;

    }
    else {

        Song song = listOfPlaylist->get(name)->playNextSong();
        lib->getSong(song.getTitle())->playSong();
        std::cout << "Song Removed: " + song.getTitle() + " " + song.getArtist() + " " +
                     std::to_string(song.getDuration()) << std::endl;
        if (listOfPlaylist->get(name)->isEmpty() == true) {
            listOfPlaylist->removePlayList(name);
            std::cout << "Playlist " + name + " is removed!" << std::endl;
        }
    }



}

std::string UserInterFace::displayLibrary(){
    std::cout<<"Display Library\n";
    return lib->display();

}

void UserInterFace::neWRandomPlayList(std::string name, int duration){
    std::cout<<"Make New Random Playlist\n";

    int tries=0;
    List* p1= new RandomPlaylist(name, duration);
    while(p1->getDuration()<duration && tries<3){
        Song songToAdd= lib->randomSong();
        tries=p1->fillRP(p1, duration, songToAdd, tries);
        p1->calcDuration();
    }


//    while(p1->getDuration()<700 && tries<3){
//        Song songToAdd= lib->randomSong();
//        tries=p1->fillRP(p1, 700, songToAdd, tries);
//        p1->calcDuration();
//    }


    listOfPlaylist->put(*p1);
    std::cout<<"New Random Playlist made: " + name + "\n";




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
    Song* testSong=lib->getSong(song);
    std::cout<<"Added " + testSong->getTitle() + " by "+ testSong->getArtist() + " with a duration of "+ std::to_string(testSong->getDuration()) + " to library\n";
}

std::string UserInterFace::removeSong(std::string name){
    std::cout<<"Remove Song\n";

    try {
        lib->getSong(name)->getTitle();
        Song* song = lib->getSong(name);
        lib->goThroughList(name);

        listOfPlaylist->goThrough(name);
        return "Song Removed: " + song->getTitle() + ", " + song->getArtist() + ", " + std::to_string(song->getDuration());

    }
    catch (std::invalid_argument &e) {

        ("Song is not in Library");
        return "Song is not in Library";
    }


}

void UserInterFace::removeSongFromPlaylist(std::string name, std::string artist, std::string title){
    std::cout<<"Remove Song From Playlist \n";

    bool isValid=true;
    try {
        listOfPlaylist->get(name);


    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        std::cout<<"Sorry Playlist does not exist \n";
        isValid=false;

    }

    if(isValid==true){
        try {
            listOfPlaylist->get(name)->getSong(title).getTitle();
            Song* song = lib->getSong(title);
            listOfPlaylist->get(name)->goThroughList(title);
            std::cout<< "Song Removed: " + song->getTitle() + ", " + song->getArtist() + ", " + std::to_string(song->getDuration()) + "\n";

        }
        catch (std::invalid_argument &e) {

            ("Song is not in Library");
            std::cout<<"Song is not in Playlist \n";
        }

    }

}

std::string UserInterFace::displayArtist(std::string artist) {
    std::cout<<"Display Artist \n";
    return lib->displayArtist(artist);

}

std::string UserInterFace::displaySong(std::string title, std::string artist){
    std::cout<<"Display Song Info \n";
    Song* song=lib->getSong(title);

    return song->getTitle() + ": Artist: " + song->getArtist() + " Duration: " + std::to_string(song->getDuration()) + " seconds  PlayCount: " + std::to_string(song->getPlayCount()) + "\n";

}

void writeFile(){

    // ofstream is used for writing files
    // We'll make a file called Sample.dat
    ofstream outf("Sample.dat");

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for writing!" << endl;
        exit(1);
    }

    // We'll write two lines into this file
    outf << "This is line 1" << endl;
    outf << "This is line 2" << endl;



    // When outf goes out of scope, the ofstream
    // destructor will close the file
}

void UserInterFace::saveFile() {
listOfPlaylist->savePlaylist();
}







int main()
{
    srand(time(NULL));


    UserInterFace ui= UserInterFace();
    ui.neW("p1");
    ui.neWRandomPlayList("Pump Up Jams", 20);
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
    ui.neWRandomPlayList("My Faves",20);
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

    ui.saveFile();




    std::cout<<"--testDone--"<<std::endl;
    std::string choice;
    while(choice!="14"){
        std::cout<<"Welcome, Please press corresponding number with choice listed"<<std::endl;
        std::cout<<" 1) HELP\n 2)Display Library\n 3)Display Playlist\n 4)Remove Song From Everything\n 5)Add Song From Library to Playlist\n 6)Add Song to Library\n 7)Play Next Song in Playlist\n 8)Display All Playlist\n 9)Display Artist\n 10)Display Song Info\n 11)Make New Playlist\n 12)Make New Random Playlist\n 13)Remove Song From Playlist\n 14)QUIT\n";
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
            std::cout<<"Please Enter Duration(seconds): \n";
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

        else if(choice=="9"){
            std::cout << "Please enter Artist name: ";
            std::string artist;
            std::getline(std::cin, artist);
            std::cout<<ui.displayArtist(artist) +"\n";
        }

        else if(choice=="10"){
            std::cout<<"Please enter Song name: ";
            std::string songTitle;
            std::getline(std::cin, songTitle);
            std::cout<<"Please enter Artist: ";
            std::string artist;
            std::getline(std::cin,artist);
            std::cout<<ui.displaySong(songTitle,artist) + "\n";

        }

        else if(choice=="11"){
            std::cout<<"Please enter new Playlist name: ";
            std::string playListName;
            std::getline(std::cin, playListName);
            ui.neW(playListName);
            std::cout<<"Playlist " + playListName + " made";
        }

        else if(choice=="12"){
            std::cout<<"Please enter new Random Playlist name: ";
            std::string randPlayListName;
            std::getline(std::cin, randPlayListName);
            std::cout<<"Please enter new Random Playlist duration: ";
            std::string duration;
            std::getline(std::cin,duration);
            std::stringstream geek(duration);
            int x=0;
            geek>>x;
            ui.neWRandomPlayList(randPlayListName,x);

        }

        else if(choice=="13"){
            std::cout<<"Please enter Playlist/RandomPlaylist name: ";
            std::string name;
            std::getline(std::cin, name);
            std::cout<<"Please enter Song title: ";
            std::string title;
            std::getline(std::cin, title);
            std::cout<<"Please enter Song artist: ";
            std::string artist;
            std::getline(std::cin, artist);
            ui.removeSongFromPlaylist(name,artist,title);


        }
    }




    return 0;

}


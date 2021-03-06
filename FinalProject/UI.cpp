
#include<iostream>
#include<string>
#include "UI.h"
#include "TestLib.h"
#include <sstream>
#include <fstream>
#include <cstdlib> // for exit()
#include <stdio.h>
#include<string.h>
using namespace std;




UserInterFace::UserInterFace(){
    listOfPlaylist= new PlayListMap();
    lib= new libraryList("Library");


}

void UserInterFace::help() {

        std::cout<<" "<<std::endl;
        std::cout<<"ALL AVAILABLE COMMANDS:"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"1: HELP (Displays all commands available to use and their summaries)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"2: Display Library (Display all songs in alphabetical order by artist (within artist alphabetical by song))"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"3: Display PlayList (Display PlayList)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"4:Remove Song From Everything (removes song from all playlists as well as the library)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"5: Add Song From Library to playlist (add a song to a playlist when given the song name, artist name, and the name of the playlist)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"6: Add Song to Library (Adds a song to the library when given the artist, title, and duration)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"7: Play Next Song in Playlist (plays the song in the playlist and then removes it, given the name of the playlist)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"8: displayArtist (Display all songs for given artist)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"9: display Artist (Display all songs for given artist given the artist name)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"10: Display Song (Display all info for a song given the artist name and song title)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"11: New Playlist (creates a new empty playlist)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"12: New Random Playlist (creates a new random playlist under a given certain duration)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"13: Remove Song from Playlist (Removes song from a playlist when given the playlist name, song name, and artist name)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"14: import (Add all songs from the given file to the library)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"15: Remove Playlist (deletes a playlist in its entirety)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"16: discontinue (Remove all songs from the given file from the library. Also remove these songs from any playlist in which they occur)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"17: QUIT (quits the program, saves all changes made)"<<std::endl;
        std::cout<<" "<<std::endl;


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
        List *p1 = listOfPlaylist->get(name);

        try {
            Song *song = lib->getSong(title, artist);
            p1->addSongToEnd(*song);
            listOfPlaylist->put(*p1);
            std::cout << "Added " + title + " to " + name + " playlist" << std::endl;

        }
        catch (std::invalid_argument &e) {
            //printAssertEquals("PlayList is not present", e.what());
            ("Song is not in Library");
            std::cout << "Song is not in Library, can't add :( \n";

        }
    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        std::cout<<"Sorry Playlist does not exist\n";
    }

}

void UserInterFace::playNext(std::string name){
    std::cout<<"Play Next Song in Playlist\n";
    try {
        listOfPlaylist->get(name);


        if (listOfPlaylist->get(name)->isEmpty() == true) {
            listOfPlaylist->removePlayList(name);
            std::cout << "Playlist " + name + " is removed!" << std::endl;

        } else {

            Song song = listOfPlaylist->get(name)->playNextSong();
            lib->getSong(song.getTitle(),song.getArtist())->playSong();
            std::cout << "Song Removed: " + song.getTitle() + " " + song.getArtist() + " " +
                         std::to_string(song.getDuration()) << std::endl;
            if (listOfPlaylist->get(name)->isEmpty() == true) {
                listOfPlaylist->removePlayList(name);
                std::string str = name + ".dat";
                char *cstr = new char[str.length() + 1];
                strcpy(cstr, str.c_str());
                if (remove(cstr) != 0) {
                    perror("Error deleting file");
                } else {
                    puts("File successfully deleted");
                }
                std::cout << "Playlist " + name + " is removed!" << std::endl;
            }
        }
    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        std::cout<<"Sorry Playlist does not exist\n";
    }



}

std::string UserInterFace::displayLibrary(){
    std::cout<<"Display Library\n";
    return lib->display();

}

void UserInterFace::neWRandomPlayList(std::string name, int duration){
    std::cout<<"Make New Random Playlist\n";
    lib->calcDuration();
    if(lib->getDuration()<duration){
        std::cout<<"There is not enough songs in the library to make a playlist with a duration this high"<<std::endl;

    }
    else {
        int tries = 0;
        List *p1 = new RandomPlaylist(name, duration);
        while (p1->getDuration() < duration && tries < 3) {
            Song songToAdd = lib->randomSong();

            try {
                p1->getSong(songToAdd.getTitle(), songToAdd.getArtist());
            }
            catch (std::invalid_argument &e) {

                ("Song is not present");
                tries = p1->fillRP(p1, duration, songToAdd, tries);
                p1->calcDuration();

            }

        }

        listOfPlaylist->put(*p1);
        std::cout << "New Random Playlist made: " + name + "\n";
    }



}

std::string UserInterFace::diplayPlaylist(std::string name){
    std::cout<<"Display Playlist\n";


    try {
        listOfPlaylist->get(name);
        if(listOfPlaylist->get(name)->isEmpty()!=true) {
            return name + ": " + listOfPlaylist->get(name)->display();
        }
        else{
            return "Nothing in playlist";
        }

    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        return "Sorry Playlist does not exist";
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
    Song* testSong=lib->getSong(song,artist);
    std::cout<<"Added " + testSong->getTitle() + " by "+ testSong->getArtist() + " with a duration of "+ std::to_string(testSong->getDuration()) + " to library\n";
}

std::string UserInterFace::removeSong(std::string name, std::string artist){
    std::cout<<"Remove Song\n";

    try {
        lib->getSong(name,artist)->getTitle();
        Song* song = lib->getSong(name,artist);
        lib->goThroughList(name, artist);

        listOfPlaylist->goThrough(name, artist);
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
        std::cout<<"Sorry Playlist does not exist :p \n";
        isValid=false;

    }

    if(isValid==true){
        try {
            listOfPlaylist->get(name)->getSong(title, artist).getTitle();
            Song* song = lib->getSong(title, artist);
            listOfPlaylist->get(name)->goThroughList(title, artist);
            std::cout<< "Song Removed: " + song->getTitle() + ", " + song->getArtist() + ", " + std::to_string(song->getDuration()) + "\n";

        }
        catch (std::invalid_argument &e) {

            ("Song is not in Library");
            std::cout<<"Song is not in Playlist :/ \n";
        }

    }

}

std::string UserInterFace::displayArtist(std::string artist) {
    std::cout<<"Display Artist \n";
    return lib->displayArtist(artist);

}

std::string UserInterFace::displaySong(std::string title, std::string artist){
    std::cout<<"Display Song Info \n";

    try {
        Song* song=lib->getSong(title, artist);
        return song->getTitle() + ": Artist: " + song->getArtist() + " Duration: " + std::to_string(song->getDuration()) + " seconds  PlayCount: " + std::to_string(song->getPlayCount()) + "\n";


    }
    catch (std::invalid_argument &e) {

        ("Song is not in Library");
        return "Song is not in Library :/ \n";
    }




}



void UserInterFace::saveFile() {
listOfPlaylist->savePlaylist();
lib->saveSongs();
}


void UserInterFace::import(std::string fileName) {
    // ifstream is used for reading files
    // We'll read from a file called Sample.dat
    ifstream inf(fileName);

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh," + fileName + " could not be opened for reading!" << endl;


    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        for(int i=0;i<4; i++) {
            std::string artist;
            getline(inf, artist);
            std::string title;
            getline(inf, title);
            std::string duration;
            getline(inf,duration);
            std::stringstream geek(duration);
            int x=0;
            geek>>x;
            std::string playcount;
            getline(inf,playcount);
            std::stringstream love(playcount);
            int y=0;
            love>>y;
            try {
                lib->getSong(title,artist)->getTitle();
                std::cout<<"Song " + title + " already in library\n";


            }
            catch (std::invalid_argument &e) {

                ("Song is not in Library");
                if(artist != "" ) {
                    Song song(artist, title, x);
                    std::cout << song.getArtist() + ", " + song.getTitle() + ", " + std::to_string(song.getDuration()) + "\n";
                    lib->addSongToEnd(song);

                    lib->getSong(song.getTitle(),song.getArtist())->setPlaycount(y);


                }


            }


        }
    }

    std::cout<<"Library was updated from songs in " + fileName + "\n";



}



void UserInterFace::startingImport(){
    // ifstream is used for reading files
    // We'll read from a file called Sample.dat
    ifstream inf("Playlist.dat");


    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Playlist.dat could not be opened for reading!" << endl;

    }

    // While there's still stuff left to read
    while (inf)
    {
        std::string playlist;
        getline(inf, playlist);
        if (playlist != "") {
            ifstream snf(playlist + ".dat");
            this->neW(playlist);

            if (!snf) {
                // Print an error and exit
                cerr << "Uh oh," + playlist + ".dat could not be opened for reading!" << endl;
                exit(1);
            }
            while (snf) {
                // read stuff from the file into a string and print it
                for (int i = 0; i < 3; i++) {
                    std::string artist;
                    getline(snf, artist);
                    std::string title;
                    getline(snf, title);
                    std::string duration;
                    getline(snf, duration);
                    std::stringstream geek(duration);
                    int x = 0;
                    geek >> x;
                    if (artist != "") {
                        Song song(artist, title, x);
                        std::cout << song.getArtist() + ", " + song.getTitle() + ", " +
                                     std::to_string(song.getDuration()) +
                                     "\n";
                        listOfPlaylist->get(playlist)->addSongToEnd(song);
                    }


                }
            }
        }
    }

std::cout<<"Playlists and Songs with in Playlists updated\n";

}



void UserInterFace::removePlaylist(std::string name) {

    try {
        listOfPlaylist->get(name);
        listOfPlaylist->removePlayList(name);
        std::string str= name+".dat";
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        if( remove( cstr ) != 0 ) {
            perror("Error deleting file");
        }
        else {
            puts("File successfully deleted");
        }
        std::cout << "Playlist " + name + " is removed!" << std::endl;

    }
    catch (std::invalid_argument &e) {
        //printAssertEquals("PlayList is not present", e.what());
        ("PlayList is not present");
        std::cout<<"Sorry Playlist does not exist";

    }


}


void UserInterFace::discontinue(std::string fileName){
    // ifstream is used for reading files
    ifstream inf(fileName);

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, " +  fileName +" could not be opened for reading!" << endl;

    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        for(int i=0;i<4; i++) {
            std::string artist;
            getline(inf, artist);
            std::string title;
            getline(inf, title);
            std::string duration;
            getline(inf,duration);
            std::stringstream geek(duration);
            int x=0;
            geek>>x;
            std::string playcount;
            getline(inf,playcount);
            std::stringstream love(playcount);
            int y=0;
            love>>y;
            if(artist != "") {
                Song song(artist, title, x);
                std::cout<<this->removeSong(title, artist) + "\n";

            }

        }
    }

}







int main()
{
    srand(time(NULL));

    std::cout<<"Toby This is the Final Version!!!!!!\n";



    UserInterFace ui= UserInterFace();
    ui.startingImport();

    ui.import("library.dat");

    std::string choice;
    std::cout<<"Welcome, Please press corresponding number with choice listed"<<std::endl;
    std::cout<<" 1) HELP\n 2)Display Library\n 3)Display Playlist\n 4)Remove Song From Everything\n 5)Add Song From Library to Playlist\n 6)Add Song to Library\n 7)Play Next Song in Playlist\n 8)Display All Playlist\n 9)Display Artist\n 10)Display Song Info\n 11)Make New Playlist\n 12)Make New Random Playlist\n 13)Remove Song From Playlist\n 14)Import\n 15)Remove PlayList\n 16)Discontinue\n 17)QUIT\n";
    std::cout<<"Please Enter Choice: ";
    std::getline(std::cin,choice);
    while(choice!="17"){
        if(choice=="1"){
            ui.help();

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
            std::cout<<"Please enter song title to remove from Playlist(s) and library: \n";
            std::string song;
            std::getline(std::cin,song);
            std::cout<<"Please enter artist of song to remove from Playlist(s) and library: \n";
            std::string artist;
            std::getline(std::cin,artist);
            std::cout<<ui.removeSong(song,artist) + "\n";
        }

        else if(choice=="5"){
            std::cout<<"Please enter Playlist, Song to add, and Artitst \n";
            std::string song;
            std::string playlist;
            std::string artist;
            std::cout<<"Please Enter Song: \n";
            std::getline(std::cin,song);
            std::cout<<"Please Enter Artist: \n";
            std::getline(std::cin,artist);
            std::cout<<"Please Enter Playlist: \n";
            std::getline(std::cin,playlist);
            ui.add(playlist,artist,song);
        }

        else if(choice=="6"){
            std::cout<<"Please enter Song to add, Artist, and Duration \n";
            std::string song;
            std::string duration;
            std::string artist;
            std::cout<<"Please Enter Song: \n";
            std::getline(std::cin,song);
            std::cout<<"Please Enter Artist: \n";
            std::getline(std::cin,artist);
            std::cout<<"Please Enter Duration(seconds): \n";
            std::getline(std::cin,duration);
            std::stringstream geek(duration);
            int x=0;
            geek>>x;
            if(x>0){
                ui.addSongToLibrary(artist,song,x);
            }
            else{
                std::cout<<"Incorrect Duration"<<std::endl;
            }

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
            if(x>0) {
                ui.neWRandomPlayList(randPlayListName, x);
            }
            else{
                std::cout<<"Incorrect Duration"<<std::endl;
            }

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

        else if(choice=="14"){
            std::string file;
            std::cout<<"Please enter file name: ";
            std::getline(std::cin, file);
            ui.import(file);
        }

        else if(choice=="15"){
            std::string name;
            std::cout<<"Please enter Playlist name: ";
            std::getline(std::cin, name);
            ui.removePlaylist(name);

        }

        else if(choice=="16"){
            std::string fileName;
            std::cout<<"Please enter file name: ";
            std::getline(std::cin,fileName);
            ui.discontinue(fileName);
        }

        std::cout<<"\n";
        std::cout<<"Welcome, Please press corresponding number with choice listed"<<std::endl;
        std::cout<<" 1) HELP\n 2)Display Library\n 3)Display Playlist\n 4)Remove Song From Everything\n 5)Add Song From Library to Playlist\n 6)Add Song to Library\n 7)Play Next Song in Playlist\n 8)Display All Playlist\n 9)Display Artist\n 10)Display Song Info\n 11)Make New Playlist\n 12)Make New Random Playlist\n 13)Remove Song From Playlist\n 14)Import\n 15)Remove PlayList\n 16)Discontinue\n 17)QUIT\n";
        std::cout<<"Please Enter Choice: ";
        std::getline(std::cin,choice);

        if(choice=="17"){
            ui.saveFile();
        }
    }




    return 0;

}


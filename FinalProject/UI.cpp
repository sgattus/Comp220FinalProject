
#include<iostream>
#include<string>
#include "UI.h"
#include "TestLib.h"



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
    if(listOfPlaylist->get(name)->isEmpty()==true){
        listOfPlaylist->removePlayList(name);
        std::cout<<"Playlist " + name + " is removed!"<<std::endl;
    }



}

std::string UserInterFace::displayLibrary(){
    return lib->display();

}

void UserInterFace::neWRandomPlayList(std::string name){
    int tries=0;
    List* p1= new RandomPlaylist(name, 100000);
    while(p1->getDuration()<700 && tries<3){
        Song songToAdd= lib->randomSong();
        //std::cout<<"in loop"<<std::endl;
        tries=p1->fillRP(p1, 700, songToAdd, tries);
        p1->calcDuration();
    }

    std::cout<<"out of loop"<<std::endl;

    listOfPlaylist->put(*p1);


    std::string dispStr= p1->display();
    std::cout<<dispStr<<std::endl;


}

std::string UserInterFace::diplayPlaylist(std::string name){

    return name + ": "+ listOfPlaylist->get(name)->display();
}

std::string UserInterFace::displayAllPlaylist(){
    return listOfPlaylist->display();
}

std::string UserInterFace::removeSong(std::string name){
    Song song=lib->getSong(name);
    lib->goThroughList(name);

    listOfPlaylist->goThrough(name);
    return"Song Removed: " + song.getTitle()+ ", " + song.getArtist()+ ", " + std::to_string(song.getDuration());

}





int main()
{
    srand(time(NULL));
    UserInterFace ui= UserInterFace();
    ui.neW("p1");
    ui.neWRandomPlayList("Pump Up Jams");
    ui.diplayPlaylist("Pump Up Jams");
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
    int choice=0;
    while(choice!=12){
        std::cout<<"Welcome, Please press corresponding number with choice listed"<<std::endl;
        std::cout<<"1) HELP\n 2)Display Library\n 3)Display Playlist\n 12)QUIT\n";
        std::cout<<"Please Enter Choice: ";
        std::cin>>choice;
        if(choice==1){
            std::cout<<"Not implemented yet, sorry :(\n";

        }
        else if(choice==2){
            std::cout<<ui.displayLibrary() + "\n";
        }
        else if(choice==3){
            std::cout<<"Please enter Playlist name: ";
            std::string playlist;
//            std::getline(std::cin,playlist);
//            //std::cout<<ui.displayAllPlaylist();
//            std::cout<<ui.diplayPlaylist(playlist) + "\n";
        }
    }




    return 0;

}


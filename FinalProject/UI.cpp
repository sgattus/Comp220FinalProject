
#include<iostream>
#include<string>
#include "UI.h"
#include "TestLib.h"
#include "PlayList.h"



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

void UserInterFace::testPlayListCopyConstructor(){
    std::cout<<"Playlist Copy Constructor Test: "<<std::endl;

    Playlist PlayList=Playlist("Pump Up Jams");

    std::cout<<"1"<<std::endl;
    Song song1 = Song("The Killers", "Mr.Brightside", 10);
    Song song2 = Song("Dr. Dog", "Heart It Races", 20);
    Song song3 = Song("Ariel Pink", "Black Ballerina", 30);
    Song song4 = Song("The Cribs","Men's Needs",40);


    std::cout<<"2"<<std::endl;
    PlayList.addSongToEnd(song1);
    PlayList.addSongToEnd(song2);

    std::cout<<"3"<<std::endl;
    Playlist copyPlaylist = Playlist(PlayList);


    std::cout<<"4"<<std::endl;
    printAssertEquals("Mr.Brightside", copyPlaylist.getSong("Mr.Brightside").getTitle());
    printAssertEquals("Heart It Races", copyPlaylist.getSong("Heart It Races").getTitle());

    std::cout<<"5"<<std::endl;
    copyPlaylist.addSongToEnd(song3);
    copyPlaylist.addSongToEnd(song4);

    std::cout<<"6"<<std::endl;
    printAssertEquals(30, copyPlaylist.getSong("Black Ballerina").getDuration());
    printAssertEquals("Men's Needs", copyPlaylist.getSong("Men's Needs").getTitle());

    std::cout<<"Done"<<std::endl;

}

void UserInterFace::testPlayListAssignmentOperator(){
    std::cout<<"Playlist Assignment Operator Test: "<<std::endl;

    Playlist PlayList2 = Playlist("Booty Jamz");

    Song song1 = Song("Jean Knight", "Mr.Big Stuff", 10);
    Song song2 = Song("Carl Carlton", "She's A Bad Mama Jama", 20);
    Song song3 = Song("Robyn", "Dancing On My Own", 30);
    Song song4 = Song("Arethra Franklin","Respect",40);

    PlayList2.addSongToEnd(song1);
    PlayList2.addSongToEnd(song2);

    Playlist PlayListToTest = Playlist("Booty Jamz Copy");

    PlayListToTest = PlayList2;

    printAssertEquals("Mr.Big Stuff", PlayListToTest.getSong("Mr.Big Stuff").getTitle());
    printAssertEquals("She's A Bad Mama Jama", PlayListToTest.getSong("She's A Bad Mama Jama").getTitle());

    PlayListToTest.addSongToEnd(song3);
    PlayListToTest.addSongToEnd(song4);

    printAssertEquals("Robyn", PlayListToTest.getSong("Dancing On My Own").getArtist());
    printAssertEquals(40, PlayListToTest.getSong("Respect").getDuration());

    std::cout<<"Done"<<std::endl;

}




int main()
{

    //test 1
    srand(time(NULL));
    UserInterFace ui= UserInterFace();
    //ui.neW("p1");
    //ui.neW("p2");
    //ui.add("p1","Genesis","That's All");
    //ui.playNext("p1");
    //std::cout<<ui.displayLibrary();
    //ui.add("p1","Men At Work","Land Down Under");
    //ui.add("p1","KerryAnne Buckman","Lullaby #5");
    //ui.playNext("p1");
    //ui.neWRandomPlayList();
    //ui.playNext("My Faves");
    //std::cout<<ui.diplayPlaylist("p1")<<std::endl;
    //std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
    //std::cout<<ui.displayLibrary()<<std::endl;

    std::cout<<"--testCopyConstructor--"<<std::endl;


    ui.testPlayListCopyConstructor();
    ui.testPlayListAssignmentOperator();



    std::cout<<"--testDone--"<<std::endl;




    return 0;

}


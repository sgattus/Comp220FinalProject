//
// Created by Kelsey Grant on 12/11/18.
// Created by Kerry Buckman ?
// Created by Sonya Gattus ?
//
#include<iostream>
#include<string.h>
#include<stdio.h>
#include "libraryList.h"
#include "Song.h"
#include "PlayListMap.h"
#include "TestLib.h"
#include "PlayList.h"

void PlayListTest(){

    cout<<"PlayListTest: "<<endl;

    libraryList* library = new libraryList("lib");

    Song song1 = Song("The Killers", "Mr. Brightside", 227);
    Song song2 = Song("Dr.Dog", "Heart It Races", 233);
    Song song3 = Song("Ariel Pink", "Black Ballerina", 350);
    Song song4 = Song("The Cribs", "Men's Needs", 195);

    library->addSongToEnd(song1);
    library->addSongToEnd(song2);
    library->addSongToEnd(song3);
    library->addSongToEnd(song4);

    List* playList= new Playlist("study music");

    try {
        playList->getSong("nothing");
        std::cout << "FAIL: get did not throw exception" << std::endl;
    }
    catch (std::invalid_argument &e) {
        printAssertEquals("Song is not present", e.what());
    }


    playList->addSongToEnd(song2);
    playList->addSongToEnd(song3);
    playList->addSongToEnd(song4);


//test 1
    cout<<"getName()/getSong() Test:"<<endl;

    printAssertEquals("Black Ballerina", playList->getSong(song3.getTitle()).getTitle());
    printAssertEquals("Heart It Races", playList->getSong(song2.getTitle()).getTitle());
    printAssertEquals("Men's Needs", playList->getSong(song4.getTitle()).getTitle());
    try {
        library->getSong("nothing");
        std::cout << "FAIL: get did not throw exception" << std::endl;
    }
    catch (std::invalid_argument &e) {
        printAssertEquals("Song is not in Library", e.what());
    }
//test 2
    cout<<"display() Test:"<<endl;

    cout<< playList->display() <<endl;

//    printAssertEquals("Mr. Brightside by The Killers(duration of 227 seconds),"
//                      " Heart It Races by Dr.Dog(duration of 233 seconds),"
//                      " Black Ballerina by Ariel Pink(duration of 350 seconds), "
//                      "Men's Needs by The Cribs(duration of 195 seconds)", playList->display());

    playList->playNextSong();
    cout<< playList->display() <<endl;

//    printAssertEquals("Heart It Races by Dr.Dog(duration of 233 seconds), "
//                      "Black Ballerina by Ariel Pink(duration of 350 seconds),"
//                      " Men's Needs by The Cribs(duration of 195 seconds)", playList->display());

    playList->playNextSong();
    cout<< playList->display() <<endl;

//    printAssertEquals( "Black Ballerina by Ariel Pink(duration of 350 seconds),"
//                       " Men's Needs by The Cribs(duration of 195 seconds)", playList->display());

    //remove rest of songs

    //playList->remove(song3);
    playList->remove(song4);

    //add them again so that they're in order for the rest of the tests

    playList->addSongToEnd(song1);
    playList->addSongToEnd(song2);
    playList->addSongToEnd(song3);
    playList->addSongToEnd(song4);

//test 3
    cout<<"calcDuration() Test:"<<endl;


    playList->calcDuration();
    printAssertEquals(1005, playList->getDuration());

    playList->remove(song1);

    playList->calcDuration();
    printAssertEquals(778, playList->getDuration());

    playList->remove(song2);
    playList->calcDuration();
    printAssertEquals(545, playList->getDuration());

//add the songs back to playList

    playList->addSongToEnd(song1);
    playList->addSongToEnd(song2);

//test 3
    cout<<"playNextSong() Test:"<<endl;

    printAssertEquals(song3.getTitle(),playList->playNextSong().getTitle());

    cout<<"isEmpty() Test:"<<endl;

    printAssertEquals(false, playList->isEmpty());

    playList->remove(song1);
    playList->remove(song2);
    playList->remove(song4);

    printAssertEquals(true, playList->isEmpty());

//add the songs back to playlist

    playList->addSongToEnd(song1);
    playList->addSongToEnd(song2);
    playList->addSongToEnd(song3);
    playList->addSongToEnd(song4);

}

//TEST COPY CONSTRUCTOR
void testPlayListCopyConstructor(){
    std::cout<<"Playlist Copy Constructor Test: "<<std::endl;
    Playlist PlayList=Playlist("Pump Up Jams");
    Song song1 = Song("The Killers", "Mr.Brightside", 10);
    Song song2 = Song("Dr. Dog", "Heart It Races", 20);
    Song song3 = Song("Ariel Pink", "Black Ballerina", 30);
    Song song4 = Song("The Cribs","Men's Needs",40);
    PlayList.addSongToEnd(song1);
    PlayList.addSongToEnd(song2);
    Playlist copyPlaylist = Playlist(PlayList);
    printAssertEquals("Mr.Brightside", copyPlaylist.getSong("Mr.Brightside").getTitle());
    printAssertEquals("Heart It Races", copyPlaylist.getSong("Heart It Races").getTitle());
    copyPlaylist.addSongToEnd(song3);
    copyPlaylist.addSongToEnd(song4);
    printAssertEquals(30, copyPlaylist.getSong("Black Ballerina").getDuration());
    printAssertEquals("Men's Needs", copyPlaylist.getSong("Men's Needs").getTitle());
    std::cout<<"Done"<<std::endl;
}
//TEST ASSIGNMENT OPERATOR
void testPlayListAssignmentOperator(){
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

void LibraryTest()
{
    cout<<"LibraryListTest: "<<endl;

    libraryList *library = new libraryList("testLib");
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);

    library->addSongToEnd(song1);
    library->addSongToEnd(song2);
    library->addSongToEnd(song3);
    library->addSongToEnd(song4);
    cout << "LibraryList.put, LibraryList.containsKey and LibraryList.get Test: " << endl;
    printAssertEquals("Box of Rain", library->getSong("Box of Rain")->getTitle());
    printAssertEquals("Land Down Under", library->getSong("Land Down Under")->getTitle());
    try {
        library->getSong("nothing");
        std::cout << "FAIL: get did not throw exception" << std::endl;
    }
    catch (std::invalid_argument &e) {
        printAssertEquals("Song is not present", e.what());
    }

    cout << "Songs Sorted in Alphabetical Order by Artist Test : ";
    printAssertEquals(
            "ARTIST1: Genesis: That's All, ARTIST2: Grateful Dead: Box of Rain, Brown Eyed Women, ARTIST3: Men At Work: Land Down Under",
            library->display());
    std::cout << "--done--" << std::endl;
}

void testLibraryCopyConstructor(){
    cout<<"Library Copy Constructor Test: "<<endl;
    libraryList LibraryToTest=libraryList("TestLibToCopy");
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);
    LibraryToTest.addSongToEnd(song1);
    LibraryToTest.addSongToEnd(song2);

    libraryList copyMap= libraryList (LibraryToTest);
    printAssertEquals("Box of Rain", copyMap.getSong("Box of Rain")->getTitle());
    printAssertEquals("That's All", copyMap.getSong("That's All")->getTitle());
    copyMap.addSongToEnd(song3);
    LibraryToTest.addSongToEnd(song4);
    printAssertEquals("Land Down Under", copyMap.getSong("Land Down Under")->getTitle());
    printAssertEquals("Brown Eyed Women", LibraryToTest.getSong("Brown Eyed Women")->getTitle());
    cout<<"--done--"<<endl;

}
//Assignment Operator Test
void testLibraryAssignmentOperator(){
    cout<<"Library Assignment Operator Test: "<<endl;
    libraryList LibraryToTest=libraryList("LibraryToTest");
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);
    LibraryToTest.addSongToEnd(song1);
    LibraryToTest.addSongToEnd(song2);
    Song garbage= Song("garbage","garbage",7978978);

    libraryList copyMap=libraryList("copyLib");
    copyMap.addSongToEnd(garbage);

    copyMap= LibraryToTest;
    printAssertEquals("Box of Rain", copyMap.getSong("Box of Rain")->getTitle());
    printAssertEquals("That's All", copyMap.getSong("That's All")->getTitle());
    copyMap.addSongToEnd(song3);
    LibraryToTest.addSongToEnd(song4);
    printAssertEquals("Land Down Under", copyMap.getSong("Land Down Under")->getTitle());
    printAssertEquals("Brown Eyed Women", LibraryToTest.getSong("Brown Eyed Women")->getTitle());
    try {
        copyMap.getSong(garbage.getTitle());
        std::cout<<"Fail, did not throw exception"<<std::endl;

    }
    catch (std::invalid_argument &e) {
        ("Song is not in Library");
        std::cout<<"pass"<<std::endl;

        }
    cout<<"--done--"<<endl;

}

int main()
{
    PlayListTest();
    testPlayListAssignmentOperator();
    testPlayListCopyConstructor();
    cout<<"--Kelsey's Playlist Test Done--"<<endl;
    LibraryTest();
    cout<<"--Library Test Done--"<<endl;
    testLibraryCopyConstructor();
    cout<<"--Library Copy Constructor Test Done--"<<endl;
    testLibraryAssignmentOperator();
    cout<<"--Library Assignment Operator Test Done--"<<endl;
    return 0;
}


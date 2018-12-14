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
#include "UI.h"

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
    cout << "Library.addSongToEnd,  Library.getSong Test: " << endl;
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

void PlayListMapTest()
{
    cout<<"PlayListMapTest: "<<endl;

    libraryList *library = new libraryList("testLib");
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);

    library->addSongToEnd(song1);
    library->addSongToEnd(song2);
    library->addSongToEnd(song3);
    library->addSongToEnd(song4);
    cout << "Library.addSongToEnd,  Library.getSong Test: " << endl;
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


    PlayListMap* p = new PlayListMap();
    List* playlist1= new Playlist("playList 1");
    p->put(*playlist1);
    cout<<"Test PlayLisMap.get(), PlayListMap.put, and PlayListMap.containsKey: "<<endl;
    printAssertEquals("playList 1", p->get("playList 1")->getName());


    List* p1=p->get("playList 1");
    p1->addSongToEnd(song1);
    p1->addSongToEnd(song2);


    printAssertEquals(song1.getTitle(),p1->getSong(song1.getTitle()).getTitle());
    printAssertEquals(song2.getTitle(),p1->getSong(song2.getTitle()).getTitle());

    List* playlist2= new Playlist("sonya");
    playlist2->addSongToEnd(song1);
    p->put(*playlist2);
    printAssertEquals(song1.getTitle(),p->get("sonya")->getSong(song1.getTitle()).getTitle());

    p->get("sonya")->addSongToEnd(song2);

    printAssertEquals("That's All",p->get("sonya")->getSong("That's All").getTitle());
    std::cout << "--done--" << std::endl;
    p->get("sonya")->remove(song2);

    try {
        printAssertEquals("That's All",p->get("sonya")->getSong("That's All").getTitle());
        std::cout << "FAIL: get did not throw exception" << std::endl;
    }
    catch (std::invalid_argument &e) {
        printAssertEquals("Song is not present", e.what());
    }

}

void randomPlaylistTest(){

    std::cout<<"---random playlist tests---"<<std::endl;

    libraryList* lib= new libraryList("Library");

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

    std::cout<<"Make New Random Playlist\n";

    int tries=0;
    List* p1= new RandomPlaylist("yeah", 50);
    while(p1->getDuration()<50 && tries<3){
        Song songToAdd= lib->randomSong();
        tries=p1->fillRP(p1, 50, songToAdd, tries);
        p1->calcDuration();
    }
    std::cout<<p1->display()<<std::endl;

    std::cout<<"adding songs"<<std::endl;
    Song s= Song("Grace Dury", "Ping the Pong in the DING DONG", 300);
    p1->addSongToEnd(s);
    Song s1 = Song("Lady Gaga", "Poker Face", 200);
    p1->addSongToEnd(s1);
    Song s2 = Song("Sia", "Chandelier", 200);
    p1->addSongToEnd(s2);
    Song s3 = Song("Kelsey-Ryan Elizabeth-Lily Grant", "i was born in a tree", 500);
    p1->addSongToEnd(s3);
    Song s4 = Song("Sonart Robitussin Guhtaytus", "it's been a coon's age", 50);
    p1->addSongToEnd(s4);
    Song s5 = Song("Katherine Louise Polley", "EP: drownin in pussy", 1000);
    p1->addSongToEnd(s5);
    Song s6 = Song("Kerry Anne Buckman", "Lullaby #5", 5);
    p1->addSongToEnd(s6);
    p1->calcDuration();
    std::cout<<p1->getDuration()<<std::endl;
    Song s7=Song("Artist", "Song Name", 200);
    p1->addSongToEnd(s7);
    std::cout<<"should increase"<<std::endl;
    p1->calcDuration();
    std::cout<<p1->getDuration()<<std::endl;
    std::cout<<"removing a song"<<std::endl;
    p1->remove(s7);
    std::cout<<"should decrease"<<std::endl;
    p1->calcDuration();
    std::cout<<p1->getDuration()<<std::endl;
    printAssertEquals(s1.getTitle(),p1->getSong(s1.getTitle()).getTitle());
    printAssertEquals(s2.getTitle(),p1->getSong(s2.getTitle()).getTitle());
    printAssertEquals("yeah", p1->getName());
    std::cout<<"stays the same"<<std::endl;
    p1->calcDuration();
    std::cout<<p1->getDuration()<<std::endl;
    std::cout<<p1->display()<<std::endl;
    std::cout<<"removes drownin in pussy"<<std::endl;
    p1->remove(s5);
    p1->calcDuration();
    std::cout<<p1->display()<<std::endl;
    std::cout<<p1->getDuration()<<std::endl;
    std::cout<<"plays song. duration decreases and first song removed"<<std::endl;
    p1->playNextSong();
    p1->calcDuration();
    std::cout<<p1->getDuration()<<std::endl;
    std::cout<<p1->display()<<std::endl;

}


//void TestingUI(){
//    UserInterFace ui=UserInterFace();
//
//        ui.neW("p1");
//    ui.neWRandomPlayList("Pump Up Jams", 20);
//    std::cout<<ui.diplayPlaylist("Pump Up Jams") + "\n";
//    ui.playNext("Pump Up Jams");
//    ui.playNext("Pump Up Jams");
//    ui.neW("p2");
//    ui.add("p2","Genesis","That's All");
//    ui.add("p1","Genesis","That's All");
//    ui.playNext("p2");
//    std::cout<<ui.displayLibrary();
//    ui.add("p1","Men At Work","Land Down Under");
//    ui.add("p1","Ween", "It's Gonna Be Alright Baby");
//    ui.add("p1","KerryAnne Buckman","Lullaby #5");
//    ui.add("p1","Kelsey Grant","I Was Born In A Tree");
//    ui.playNext("p1");
//    ui.neWRandomPlayList("My Faves",20);
//    ui.playNext("My Faves");
//    std::cout<<ui.diplayPlaylist("p1")<<std::endl;
//    std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
//    std::cout<<ui.displayLibrary()<<std::endl;
//    std::cout<<ui.displayAllPlaylist()<<std::endl;
//    ui.playNext("p1");
//    std::cout<<ui.displayLibrary()<<std::endl;
//    std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
//    std::cout<<ui.diplayPlaylist("p1")<<std::endl;
//    std::cout<<ui.removeSong("Lullaby #5")<<std::endl;
//    std::cout<<ui.diplayPlaylist("p1")<<std::endl;
//    std::cout<<ui.diplayPlaylist("My Faves")<<std::endl;
//    std::cout<<ui.displayLibrary()<<std::endl;
//
//    std::cout<<"User Interface Test Done"<<std::endl;
//}


int main()
{
    srand(time(NULL));
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
    PlayListMapTest();
    std::cout << "--PlayListMap Test Done--" << std::endl;
    randomPlaylistTest();
    std::cout<<"--Random PlayListTest Done--"<<std::endl;
    //TestingUI();
    std::cout<<"Done with Tests"<<std::endl;
    return 0;
}


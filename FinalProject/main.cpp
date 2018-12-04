#include<iostream>
#include<string.h>
#include<stdio.h>
#include "LibraryMap.h"
#include "Song.h"
#include "PlayListMap.h"
#include "UserInterFace.h"
#include "TestLib.h"
#include "PlayList.h"

using namespace std;

void LibraryMapTest()
{
    cout<<"LibraryMapTest: "<<endl;

    LibraryMap<Song> *library = new LibraryMap<Song>();
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);

    library->put(song1);
    library->put(song2);
    library->put(song3);
    library->put(song4);
    cout << "LibraryMap.put, LibraryMap.containsKey and LibraryMap.get Test: " << endl;
    printAssertEquals("Box of Rain", library->get("Box of Rain")->getTitle());
    printAssertEquals("Land Down Under", library->get("Land Down Under")->getTitle());
    try {
        library->get("nothing");
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

//Copy Constructor Test
void testLibraryCopyConstructor(){
    cout<<"Library Copy Constructor Test: "<<endl;
    LibraryMap<Song> LibraryToTest;
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);
    LibraryToTest.put(song1);
    LibraryToTest.put(song2);

    LibraryMap<Song> copyMap= LibraryMap<Song> (LibraryToTest);
    printAssertEquals("Box of Rain", copyMap.get("Box of Rain")->getTitle());
    printAssertEquals("That's All", copyMap.get("That's All")->getTitle());
    copyMap.put(song3);
    LibraryToTest.put(song4);
    printAssertEquals("Land Down Under", copyMap.get("Land Down Under")->getTitle());
    printAssertEquals("Brown Eyed Women", LibraryToTest.get("Brown Eyed Women")->getTitle());
    cout<<"--done--"<<endl;

}

//Assignment Operator Test
void testLibraryAssignmentOperator(){
    cout<<"Library Assignment Operator Test: "<<endl;
    LibraryMap<Song> LibraryToTest;
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);
    LibraryToTest.put(song1);
    LibraryToTest.put(song2);

    LibraryMap<Song> copyMap;
    copyMap= LibraryToTest;
    printAssertEquals("Box of Rain", copyMap.get("Box of Rain")->getTitle());
    printAssertEquals("That's All", copyMap.get("That's All")->getTitle());
    copyMap.put(song3);
    LibraryToTest.put(song4);
    printAssertEquals("Land Down Under", copyMap.get("Land Down Under")->getTitle());
    printAssertEquals("Brown Eyed Women", LibraryToTest.get("Brown Eyed Women")->getTitle());
    cout<<"--done--"<<endl;

}
void PlayListMapTest()
{
    cout<<"PlayListMapTest: "<<endl;

    LibraryMap<Song> *library = new LibraryMap<Song>();
    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);

    library->put(song1);
    library->put(song2);
    library->put(song3);
    library->put(song4);
    cout << "LibraryMap.put, LibraryMap.containsKey and LibraryMap.get Test: " << endl;
    printAssertEquals("Box of Rain", library->get("Box of Rain")->getTitle());
    printAssertEquals("Land Down Under", library->get("Land Down Under")->getTitle());
    try {
        library->get("nothing");
        std::cout << "FAIL: get did not throw exception" << std::endl;
    }
    catch (std::invalid_argument &e) {
        printAssertEquals("Song is not present", e.what());
    }

    cout << "Songs Sorted in Alphabetical Order by Artist Test : ";
    printAssertEquals(
            "ARTIST1: Genesis: That's All, ARTIST2: Grateful Dead: Box of Rain, Brown Eyed Women, ARTIST3: Men At Work: Land Down Under",
            library->display());


    PlayListMap<List>* p = new PlayListMap<List>();
    p->setLibrary(*library);
    List* playlist1= new Playlist("playList 1");
    p->put(*playlist1);
    cout<<"Test PlayLisMap.get(), PlayListMap.put, and PlayListMap.containsKey: "<<endl;
    printAssertEquals("playList 1", p->get("playList 1")->getName());

    //playlist1.addSongToEnd(song1);
    List* p1=p->get("playList 1");
    p1->addSongToEnd(song1);
    p1->addSongToEnd(song2);


    printAssertEquals(song1.getTitle(),p1->getSong(song1.getTitle()).getTitle());
    printAssertEquals(song2.getTitle(),p1->getSong(song2.getTitle()).getTitle());

    List* playlist2= new Playlist("sonya");
    //playlist2->setName("sonya");
    playlist2->addSongToEnd(song1);
    p->put(*playlist2);
    printAssertEquals(song1.getTitle(),p->get("sonya")->getSong(song1.getTitle()).getTitle());
//    playlist2 = p->get("sonya");
//    playlist2.addSongToEnd(song2);
//
//    p->put(playlist2);
    //p->add("sonya", song2.getArtist(), song2.getTitle());
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

    UserInterFace UI=UserInterFace(p);
    cout<<UI.displayLibrary()<<endl;
    UI.neW("pump up jams");
    UI.add("pump up jams","Genesis", "That's All");




    std::cout << "--done--" << std::endl;
}

void PlayListTest(){

    cout<<"PlayListTest: "<<endl;

    LibraryMap<Song> *library = new LibraryMap<Song>();

    Song song1 = Song("The Killers", "Mr. Brightside", 227);
    Song song2 = Song("Dr.Dog", "Heart It Races", 233);
    Song song3 = Song("Ariel Pink", "Black Ballerina", 350);
    Song song4 = Song("The Cribs", "Men's Needs", 195);

    library->put(song1);
    library->put(song2);
    library->put(song3);
    library->put(song4);

    List* playList= new Playlist("study music");
    if(library->containsKey(song1.getTitle())){
        playList->addSongToEnd(song1);
    }
    else{
        cout<<"Song is not in library"<<endl;
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
        library->get("nothing");
        std::cout << "FAIL: get did not throw exception" << std::endl;
    }
    catch (std::invalid_argument &e) {
        printAssertEquals("Song is not present", e.what());
    }
//test 2
    cout<<"display() Test:"<<endl;

    //cout<< playList->display() <<endl;

    printAssertEquals("Mr. Brightside by The Killers(duration of 227 seconds),"
                      " Heart It Races by Dr.Dog(duration of 233 seconds),"
                      " Black Ballerina by Ariel Pink(duration of 350 seconds), "
                      "Men's Needs by The Cribs(duration of 195 seconds)", playList->display());

    playList->playNextSong();

    printAssertEquals("Heart It Races by Dr.Dog(duration of 233 seconds), "
                      "Black Ballerina by Ariel Pink(duration of 350 seconds),"
                      " Men's Needs by The Cribs(duration of 195 seconds)", playList->display());

    playList->playNextSong();

    printAssertEquals( "Black Ballerina by Ariel Pink(duration of 350 seconds),"
                       " Men's Needs by The Cribs(duration of 195 seconds)", playList->display());

    //remove rest of songs

    playList->remove(song3);
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

//test 5
    cout<<"clearList() Test:"<<endl;

    playList->clearList();

    printAssertEquals(true, playList->isEmpty());

    cout<<"--done--"<<endl;
}

int main()
    {

    LibraryMapTest();
    testLibraryCopyConstructor();
    testLibraryAssignmentOperator();
    PlayListMapTest();
    PlayListTest();
    cout<<"--testDone--"<<endl;

    return 0;

}
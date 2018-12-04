#include<iostream>
#include<string.h>
#include<stdio.h>
#include "LibraryMap.h"
#include "Song.h"
#include "PlayListMap.h"
#include "UserInterFace.h"
#include "TestLib.h"
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
    //cout<<UI.displayLibrary()<<endl;
    UI.neW("red");
    UI.add("red","Genesis", "That's All");
    PlayListMap<List>* map=UI.getPlayList();
    UI.playNext("red",*map);
    //map->get("red")->addSongToEnd(song1);
    //Song song = map->playNext("red");
    //std::cout<<song.getTitle()<<song.getArtist();






 std::cout<<"help"<<endl;





    std::cout << "--done--" << std::endl;
}

void UITest(){

    PlayListMap<List> playListMap= PlayListMap<List>();


}



int main()
    {

//    LibraryMapTest();
//    testLibraryCopyConstructor();
//    testLibraryAssignmentOperator();
    PlayListMapTest();
    cout<<"--testDone--"<<endl;




    return 0;

}
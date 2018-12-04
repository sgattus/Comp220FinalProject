

#include "UI.h"
#include <iostream>

UserInterFace::UserInterFace(){
    listOfPlaylist= PlayListMap<List>();
    libraryMap= new LibraryMap<Song>();

    Song song1 = Song("Grateful Dead", "Box of Rain", 2);
    Song song2 = Song("Genesis", "That's All", 2);
    Song song3 = Song("Men At Work", "Land Down Under", 2);
    Song song4 = Song("Grateful Dead", "Brown Eyed Women", 4);

    libraryMap->put(song1);
    libraryMap->put(song2);
    libraryMap->put(song3);
    libraryMap->put(song4);

    listOfPlaylist.setLibrary(*libraryMap);
}

void UserInterFace::neW(std::string name){
    List* playlist= new Playlist(name);
    listOfPlaylist.put(*playlist);

}

void UserInterFace::add(std::string name, std::string artist, std::string title){
    if(listOfPlaylist.getLibrary()->containsKey(title)==true){
        List* p1=listOfPlaylist.get(name);
        p1->addSongToEnd(*listOfPlaylist.getLibrary()->get(title));
        listOfPlaylist.put(*p1);
        cout<<"Added " + title + "to " + name+ " playlist"<<endl;
        cout<<"check " + listOfPlaylist.get(name)->getSong(title).getTitle()<<endl;
    }
    else{
        cout<<"Song is not in Library"<<endl;
    }
}

void UserInterFace::playNext(std::string name){
    std::cout<<"hey"<<std::endl;
    List* p1=listOfPlaylist.get(name);
    listOfPlaylist.put(*p1);


}



int main()
{

    UserInterFace ui= UserInterFace();
    ui.neW("p1");
    ui.neW("p2");
    ui.add("p1","Genesis","That's All");
    ui.playNext("p1");
    cout<<"--testDone--"<<endl;




    return 0;

}


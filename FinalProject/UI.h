#ifndef UI
#define UI

#include "Map.h"
#include "PlayListMap.h"



class UserInterFace{
private:
    PlayListMap<List> listOfPlaylist;
    LibraryMap<Song>* libraryMap;


public:
    UserInterFace();
    void neW(std::string name);
    void add(std::string name, std::string artist, std::string title);
    void playNext(std::string name);
    PlayListMap<List> getPlayListMap();
    std::string displayLibrary();



};

#endif
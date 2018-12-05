#ifndef UI
#define UI

#include "Map.h"
#include "PlayListMap.h"
#include "List.h"
#include "libraryList.h"


class UserInterFace{
private:
    PlayListMap* listOfPlaylist;
    List* lib;


public:
    UserInterFace();
    void neW(std::string name);
    void add(std::string name, std::string artist, std::string title);
    void playNext(std::string name);
    void neWRandomPlayList(std::string name);

    std::string displayLibrary();

    //void help();
    std::string diplayPlaylist(std::string name);
    std::string displayAllPlaylist();



};

#endif
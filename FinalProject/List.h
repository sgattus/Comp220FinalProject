
#ifndef COMP220_LIST_H
#define COMP220_LIST_H

#include <stdexcept>
#include <string>
#include "Song.h"

class List {
private:
    //Private to disable copying and assigning from outside class, don't implement these methods


public:
    //constructor
    List() {}

    List(const List& listToCopy);
//    virtual List& operator=(const List& listToCopy)=0;

    //Destructor
    virtual ~List() {}

     virtual void addSongToEnd(Song& songToAdd)=0;
     virtual void remove(Song songToRemove)=0;
    /**
    * Display all the names of the playlist and their durations
    * •	return a string representing all songs in the playlist
    */
     virtual std::string display()=0;


    /**
    *calculate the duration of the playlist
    */
    virtual void calcDuration()=0;

    virtual Song getSong(std::string title)=0;



    /**
   *play next song, returning song info and removing it from playlist (playnext)
     * Through exception if no more songs
    **/
    virtual Song playNextSong()=0;

    /**
     * •	check if empty
     */
    virtual bool isEmpty()=0;

    /**
     *
     */
    virtual std::string getName()=0;

    //needs to be inherently called in rand play
    virtual  int fillRP(List* p, int maxDuration, Song& songToAdd, int tries)=0;

    //needs to be inherently called in rand play
    virtual Song randomSong()=0;

    virtual int getDuration()=0;

    virtual void goThroughList(std::string name)=0;







};


#endif //COMP220_LIST_H

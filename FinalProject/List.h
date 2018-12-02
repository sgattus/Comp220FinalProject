
#ifndef COMP220_LIST_H
#define COMP220_LIST_H

#include <stdexcept>
#include <string>

class List {
private:
    //Private to disable copying and assigning from outside class, don't implement these methods
    List(const List& listToCopy);
    List& operator=(const List& listToCopy);

public:
    //constructor
    List() {}

    //Destructor
    virtual ~List() {}

     virtual void addSongToEnd(Song songToAdd)=0;
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

    /**
     *
     */
    virtual int getDuration()=0;





};


#endif //COMP220_LIST_H

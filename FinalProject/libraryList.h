#ifndef LIBRARYLIST_H
#define LIBRARYLIST_H

#include <string>
#include "LinkedNode.h"
#include "Song.h"
#include "List.h"


class libraryList {
private:
    LinkedNode<Song> *head;
    LinkedNode<Song>  *end;
    std::string name;
    int duration;

    int size;

public:
    libraryList(std::string name);

        libraryList(const libraryList& libraryListToCopy);
        libraryList& operator=(const libraryList& libraryListToCopy);
    ~libraryList();
    void addSongToEnd(Song& songToAdd);
    void remove(Song songToRemove);
    Song* getSong(std::string title, std::string artist);
    Song randomSong();

    /**
     * These are commited out for my test to run since they do not have definitions yet
     * Go ahead and COMMENT out my test in main and make your own to implement these
     * Please do not edit addSongToEnd, remove, and getSong unless you talk to me
     * Same with constructor
     */

    /**
    * Display all the names of the playlist and their durations
    * •	return a string representing all songs in the playlist
    */


    std::string display();

    /**
    *calculate the duration of the playlist
    */
    void calcDuration();


    /**
     * •	check if empty
     * return true if empty
     */
    bool isEmpty();



    void clearList();

    int getDuration();



    void goThroughList(std::string name, std::string artist);

    std::string displayArtist(std::string artist);

    void saveSongs();





};




#endif //PLAYLIST_H
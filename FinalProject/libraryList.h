#ifndef LIBRARYLIST_H
#define LIBRARYLIST_H

#include <string>
#include "LinkedNode.h"
#include "Song.h"
#include "List.h"


class libraryList: public List {
private:
    LinkedNode<Song> *head;
    LinkedNode<Song>  *end;
    std::string name;
    int duration;

    int size;

public:
    libraryList(std::string name);

//        Playlist(const Playlist& playlistToCopy);
//        Playlist<T>& operator=(const Playlist<T>& playlistToCopy);
    ~libraryList();
    void addSongToEnd(Song& songToAdd);
    void remove(Song songToRemove);
    Song getSong(std::string title);

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

    //Committed out for testing purposes
    std::string display();

    /**
    *calculate the duration of the playlist
    */
    void calcDuration();

    /**
   *play next song, returning song info and removing it from playlist (playnext)
     * Through exception if no more songs
    **/
    Song playNextSong();

    /**
     * •	check if empty
     * return true if empty
     */
    bool isEmpty();

    /**
     *
     */
    std::string getName();

    void clearList();

    int getDuration();





};




#endif //PLAYLIST_H
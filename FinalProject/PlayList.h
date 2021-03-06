#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "LinkedNode.h"
#include "Song.h"
#include "List.h"


class Playlist: public List {
private:
    LinkedNode<Song> *head;
    LinkedNode<Song>  *end;
    std::string name;
    int duration;

    int size;

public:
    Playlist(std::string name);

    Playlist(const Playlist& playlistToCopy);
    Playlist& operator=(const Playlist& playlistToCopy);
    ~Playlist();
    void addSongToEnd(Song& songToAdd);
    void remove(Song songToRemove);
    Song getSong(std::string title, std::string artist);

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

    int fillRP(List* p, int maxDuration, Song& songToAdd, int tries);

    Song randomSong();

    void goThroughList(std::string name, std::string artist);

    void saveSongs(std::string fileName);





};




#endif //PLAYLIST_H
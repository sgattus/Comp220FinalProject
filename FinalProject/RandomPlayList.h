#ifndef RANDOMPLAYLIST_H
#define RANDOMPLAYLIST_H

#include <string>
#include "LinkedNode.h"
#include "Song.h"
#include "List.h"

template <class T>
class RandomPlaylist:public List<T> {
private:
    LinkedNode<T> *head;
    LinkedNode<T>  *end;
    std::string name;
    int duration;

    int size;

public:
    /**
     * Creates playlist with random songs that add up to user entered duration
     * @param name
     * @param duration
     */
    RandomPlaylist(std::string name, int duration);
    RandomPlaylist(const RandomPlaylist<T>& playlistToCopy);
    RandomPlaylist<T>& operator=(const RandomPlaylist<T>& playlistToCopy);
    void addSongToEnd(Song songToAdd);
    void remove(Song songToRemove);
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
   *play next song, returning song info and removing it from playlist (playnext)
     * Through exception if no more songs
    **/
    Song playNextSong();

    /**
     * •	check if empty
     */
    bool isEmpty();

    /**
     *
     */



};

#include "RandomPlayList.inl"


#endif //PLAYLIST_H
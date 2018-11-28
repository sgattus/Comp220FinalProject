#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "LinkedNode.h"
#include "Song.h"

class Playlist {
    private:
        LinkedNode<Song> *head;
        LinkedNode<Song>  *end;
        std::string name;
        int duration;

        int size;

    public:
        Playlist(std::string name);
//        Playlist(const Playlist& playlistToCopy);
//        Playlist<T>& operator=(const Playlist<T>& playlistToCopy);
        ~Playlist();
        void addSongToEnd(Song songToAdd);
        void remove(Song songToRemove);
        Song getSong(std::string title);

        /**
        * Display all the names of the playlist and their durations
        * •	return a string representing all songs in the playlist
        */

        //Committed out for testing purposes
//        std::string display();
//
//        /**
//        *calculate the duration of the playlist
//        */
//         void calcDuration();
//
//         /**
//        *play next song, returning song info and removing it from playlist (playnext)
//          * Through exception if no more songs
//         **/
//         Song playNextSong();
//
//         /**
//          * •	check if empty
//          */
//          bool isEmpty();

          /**
           *
           */
           std::string getName();



};




#endif //PLAYLIST_H
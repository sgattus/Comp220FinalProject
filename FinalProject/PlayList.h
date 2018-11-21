#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "LinkedNode.h"
#include "Song.h"
#include "List.h"

template <class T>
class Playlist:public List<T> {
    private:
        LinkedNode<T> *head;
        LinkedNode<T>  *end;
        std::string name;
        int duration;

        int size;

    public:
        Playlist(std::string name);
        Playlist(const Playlist& playlistToCopy);
        Playlist<T>& operator=(const Playlist<T>& playlistToCopy);
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

#include "PlayList.inl"


#endif //PLAYLIST_H
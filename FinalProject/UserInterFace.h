#ifndef USERINTERFACE
#define USERINTERFACE

#include "PlayListMap.h"
#include "Map.h"
#include "RandomPlayList.h"
#include "LibraryMap.h"
#include "PlayList.h"
#include "Song.h"
#include "List.h"


class UserInterFace{
    private:
    PlayListMap<List>* listOfPlaylist;


    public:
    UserInterFace(PlayListMap<List>* listOfPlaylistIn);

    /**
     * Provide a summary of all available commands.
     */
    void help();

    /**
     * Display all songs in alphabetical order by artist (within artist alphabetical by song)
     */
     std::string displayLibrary();

     /**
      * Display PlayList
      */
      std::string diplayPlaylist(std::string name);

      /**
       * Diplay all the playlists
       */
      std::string displayAllPlaylist();

      /**
       * Display all songs for given artist
       */
       std::string displayArtist(std::string artist);

       /**
        * Display all songs for given artist
        */
        std::string displaySong(std::string song);

        /**
         * Add all songs from the given file to the library.
         * Print message to the user of any songs that already existed (do not add duplicates)
         * fileName parameter ?
         */
         void import(std::string fileName);


         /**
          * Remove all songs from the given file from the library. Also remove these songs from any playlist in which they occur.
          * Print message to the user of any songs that were not present (couldn't be removed).
          */
          void discontinue(std::string fileName);

          /**
           * Make a new empty playlist with the given name
           */
           void neW(std::string name);

           /**
            * Add the given song to the end of the given playlist
            */
            void add(std::string name, std::string artist, std::string title);

            /**
             * Print all information about the next song to be played from the given playlist to the screen.
             * Remove that song from the given playlist.
             * Add to the playcount for that song in the library.
             * If the playlist is now empty, it should be removed.
             */
             void playNext(std::string name);

             /**
              * Make a new playlist with the given name, and populate it with a random group of songs that do not repeat
              * (within this playlist) and are in some shuffled order
              * (i.e., if the same random songs were chosen for another playlist, they should not play in the same order each time).
              */
              void newRandom(std::string name, int duration);

              /**
               * Save the library and all playlists and terminate execution.
               */

                void quit();

                PlayListMap<List>* getPlayList();


};






#endif
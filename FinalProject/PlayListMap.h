#ifndef PLAYLISTMAP_H
#define PLAYLISTMAP_H

#include <string>
#include "LinkedNode.h"
#include "Map.h"
#include "LibraryMap.h"
#include "PlayList.h"
#include "RandomPlayList.h"

template <class T>
class PlayListMap: public Map<T>{
private:
    LinkedNode<Playlist> *head;
    LinkedNode<Playlist>  *end;
    //acess to the library
    LibraryMap<Song> *libray;

    int size;


//
public:
    /**
     * Constructor
     */

    PlayListMap();

    //Copy Constructor
//    PlayListMap(const PlayListMap<T>& PlayListMapToCopy);
//
//    //Assignment Operator
//    PlayListMap<T>& operator=(const PlayListMap<T>& PlayListMapToCopy);






    //Destructor
   // ~PlayListMap();

    /**
   *Add Play List to map of playlists
   */

    void setLibrary(LibraryMap<Song> lib);
    void put(Playlist& value);

    //Might Not Need this
//    /**
//     * •	add a new random playlist (newrandom)
//     */
//
//    void putRand(int duration);


    void add(Song song, std::string name);


    /**
      *remove the given song from given playlist
     * Use this.get to find playlist
     *
     *Use playlist remove song from given playlist
     */
    void remove(std::string name, std::string artist, std::string title);


    /**
    * @return the value associated with the given name
    * @throws std::invalid_argument if the name is not present
    */
    Playlist get(std::string name);

    /**
     * @return true if the given name is associated with a value in the map, false otherwise
     */
    bool containsKey(std::string name);

    /**
     * Display all the names of the playlist and their durations
     * •	return a string representing all songs in the playlist
     */
    std::string display();

    /**
     * •	display the contents of a particular playlist (playlist)
     */
     std::string displayPlayList();

     /**
      * Remove PlayList When empty (becomes empty from deletion after playnext)
      */
      void removePlayList(std::string name);



};

#include "PlayListMap.inl"

#endif //LINKEDLISTMAP_H
#ifndef PLAYLISTMAP_H
#define PLAYLISTMAP_H

#include <string>
#include "LinkedNode.h"
#include "Map.h"
#include "LibraryMap.h"
#include "PlayList.h"
#include "RandomPlayList.h"


class PlayListMap: public Map{
private:
    LinkedNode<List> *head;
    LinkedNode<List>  *end;
    //acess to the library


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


    void put(List& value);




    /**
    * @return the value associated with the given name
    * @throws std::invalid_argument if the name is not present
    */
    List* get(std::string name);

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



    Song playNext(std::string name);



};



#endif //LINKEDLISTMAP_H
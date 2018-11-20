#ifndef PLAYLISTMAP_H
#define PLAYLISTMAP_H

#include <string>
#include "LinkedNode.h"
#include "Map.h"

template <class T>
class PlayListMap: public Map<T> {
private:
    LinkedNode<T> *head;
    LinkedNode<T>  *end;

    int size;


//
public:
    /**
     * Constructor
     */

    PlayListMap();

    //Copy Constructor
    PlayListMap(const PlayListMap<T>& PlayListMapToCopy);

    //Assignment Operator
    PlayListMap<T>& operator=(const PlayListMap& PlayListMapToCopy);




    //Destructor
    ~LinkedListMap();

    /**
   *Add Play List to map of playlists
   */
    void put(const T& value);

    /**
     * @return the value associated with the given name
     * @throws std::invalid_argument if the name is not present
     */
    T get(std::string name);

    /**
     * @return true if the given key is associated with a value in the map, false otherwise
     */
    bool containsKey(std::string name);

    /**
     * Display all the names of the playlist and their durations
     */
    void display();




};

#include "PlayListMap.inl"

#endif //LINKEDLISTMAP_H
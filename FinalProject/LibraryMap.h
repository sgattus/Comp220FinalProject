#ifndef LIBRARYMAP_H
#define LIBRARYMAP_H

#include <string>
#include "LinkedNode.h"
#include "Map.h"

template <class T>
class LibraryMap: public Map<T> {
private:
    LinkedNode<T> *head;
    LinkedNode<T>  *end;

    int size;



        /**
     * •	Save the current library when program execution terminates (quit command).
    *Restore the current inventory items when program execution begins again.

     */
    void save();
    void restor();


    /**
    * •	add songs to the library (import).
    */

    void import();

    /**
    * •	remove songs from the library (discontinue).
    */
    void discountinue();

//
public:
    /**
     * Constructor
     */

    LibraryMap();

    //Copy Constructor
    LibraryMap(const LibraryMap<T>& LibraryMapToCopy);

    //Assignment Operator
    LibraryMap<T>& operator=(const LibraryMap& LibraryMapToCopy);




    //Destructor
    ~LibraryMap();

    /**
   * @post if the song is new, the song-value pair is added to the map
   *       if the song was already present, the new value overwrites the old value
   *       (i.e., the new value will be returned by get instead of the old value)
   */
    void put(const T& value);



    /**
     * @return the value associated with the given key
     * @throws std::invalid_argument if the key is not present
     */


    T get(std::string songName);

    /**
     * @return true if the given song is associated with a value in the map, false otherwise
     */
    bool containsKey(std::string songName);

    /**
     * Display all songs in alphabetical order by artist (within artist alphabetical by song)
     */
    std::string display();




};

#include "LibraryMap.inl"

#endif //LINKEDLISTMAP_H
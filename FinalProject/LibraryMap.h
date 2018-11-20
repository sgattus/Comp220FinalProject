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
    ~LinkedListMap();

    /**
   * @post if the key is new, the key-value pair is added to the map
   *       if the key was already present, the new value overwrites the old value
   *       (i.e., the new value will be returned by get instead of the old value)
   */
    void put(const T& value);

    /**
     * @return the value associated with the given key
     * @throws std::invalid_argument if the key is not present
     */
    T get(std::string name);

    /**
     * @return true if the given key is associated with a value in the map, false otherwise
     */
    bool containsKey(std::string name);

    /**
     * Display all songs from library in alphabetical order
     */
    void display();


};

#include "LibraryMap.inl"

#endif //LINKEDLISTMAP_H
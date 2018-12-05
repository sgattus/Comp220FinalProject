//
// Created by Sonya on 11/20/18.
//

#ifndef MAP_H
#define MAP_H

#include <string>
#include "Song.h"
#include "List.h"


class Map {
public:
    //virtual destructor to allow child destructor to be called
    virtual ~Map(){}

    /*
     * @post if the key is new, the key-value pair is added to the map
     *       if the key was already present, the new value overwrites the old value
     *       (i.e., the new value will be returned by get instead of the old value)
     */
    virtual void put(List& value) =0;

    /*
     * @return the value associated with the given key
     * @throws std::invalid_argument if the key is not present
     */
    virtual List* get(std::string name) =0;

    /*
     * @return true if the given key is associated with a value in the map, false otherwise
     */
    virtual bool containsKey(std::string name) =0;

    virtual Song playNext(std::string name)=0;

    virtual void goThrough(std::string name)=0;

};

#endif //MAP_H

#ifndef LIST_H
#define LIST_H

#include <string>
#include "Song.h"

template <class T>
class List {
public:
    virtual ~List(){}

    virtual void addSongToEnd(Song songToAdd)=0;
    virtual void remove(Song songToRemove)=0;
    virtual  std::string display()=0;
    virtual  void calcDuration()=0;
    virtual bool isEmpty()=0;


};

#endif //LIST_H
//
// Created by Sonya Gattus on 11/20/18.
//

#include "Song.h"

Song::Song(std::string artistIn, std::string titleIn, int durationIn){
    artist=artistIn;
    title=titleIn;
    duration=durationIn;
    playcount=0;
}

Song::Song(const Song& songToCopy){
    artist=songToCopy.artist;
    title=songToCopy.title;
    duration=songToCopy.duration;
    playcount=songToCopy.playcount;

}

Song& Song::operator=(const Song& songToCopy){
    if(this!= &songToCopy){
        artist=songToCopy.artist;
        title=songToCopy.title;
        duration=songToCopy.duration;
        playcount=songToCopy.playcount;
    }
    return* this;
}

Song::~Song(){

}

std::string Song::getArtist() {
    return artist;
}

std::string Song::getTitle() {
    return title;
}

int Song::getDuration() {
    return duration;
}

int Song::getPlayCount() {
    return playcount;
}

void Song::playSong(){
    playcount +=1;
}
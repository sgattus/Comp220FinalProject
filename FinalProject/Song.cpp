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
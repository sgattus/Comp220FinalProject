
#ifndef SONG_H
#define SONG_H

#include <string>

class Song {

private:
    std::string artist;
    std::string title;
    int duration;
    int playcount;




public:
    Song(const Song& songToCopy);
    Song& operator=(const Song& songToCopy);
    ~Song();

    Song(std::string artistIn,std::string titleIn, int durationIn);

    std::string getArtist();
    void setPlaycount(int playcount);
    std::string getTitle();
    int getDuration();
    int getPlayCount();
    void playSong();


};





#endif //SONG_H
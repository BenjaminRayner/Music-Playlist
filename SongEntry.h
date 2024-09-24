//
// Created by benja on 2021-01-22.
//

#ifndef PROJECT0_SONGENTRY_H
#define PROJECT0_SONGENTRY_H

#include <string>

class SongEntry {

private:
    std::string songName;
    std::string songArtist;

public:
    void setName_Artist(std::string name, std::string artist);
    std::string getName();
    std::string getArtist();
};


#endif //PROJECT0_SONGENTRY_H

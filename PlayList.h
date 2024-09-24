//
// Created by benja on 2021-01-22.
//

#ifndef PROJECT0_PLAYLIST_H
#define PROJECT0_PLAYLIST_H

#include "SongEntry.h"

class PlayList {

private:
    SongEntry* musicList;

public:
    PlayList(int size);
    ~PlayList();

    void addtoPlaylist(std::string song, std::string artist);
    void playMusic(int n);
    void erase (int n);
    bool duplicate(std::string name, std::string artist);

    int songCount;
    int listSize;
};


#endif //PROJECT0_PLAYLIST_H

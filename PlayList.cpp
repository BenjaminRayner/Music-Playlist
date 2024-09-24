//
// Created by benja on 2021-01-22.
//
#include "PlayList.h"
#include <iostream>

// instantiates size of playlist
PlayList::PlayList(int const size) 
{
    songCount = 0;
    listSize = size;
    musicList = new SongEntry[size];
}
// frees memory if playlist goes out of scope
PlayList::~PlayList() 
{
    delete[] musicList;
    musicList = nullptr;
    std::cout << "Test" << std::endl;
}

// SongEntry object is stored in playlist array (with song name and author)
void PlayList::addtoPlaylist(std::string const song, std::string const artist) 
{
    musicList[songCount].setName_Artist(song, artist);
    ++songCount;
}
// Plays song at index n-1; shows name and author
void PlayList::playMusic(int const n) 
{
    std::cout << "played " << n << " " << musicList[n-1].getName() << ';' << musicList[n-1].getArtist() << std::endl;
}
// overwrites song at n-1 and moves shuffles everything down 1
void PlayList::erase(int const n) 
{
    --songCount;
    for(int i = 0; (n - 1) + i < songCount; ++i) {
        musicList[n-1+i] = musicList[n+i];
    }
}
// checks for exact duplicates in the playlist
bool PlayList::duplicate(std::string const name, std::string const artist) 
{
    for (int i=0; i < songCount; ++i) {
        if (musicList[i].getName() == name && musicList[i].getArtist() == artist) {
            return true;
        }
    }
    return false;
}


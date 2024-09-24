//
// Created by benja on 2021-01-22.
//

#include "SongEntry.h"

// accesses member variables and writes to them
void SongEntry::setName_Artist(std::string const name, std::string const artist) {
    this->songName = name;
    this->songArtist = artist;
}

// access song name
std::string SongEntry::getName() {
    return this->songName;
}

// access song artist
std::string SongEntry::getArtist() {
    return this->songArtist;
}

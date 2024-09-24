//
// Created by benja on 2021-01-22.
//

//read commands from input and writes to output

#include "PlayList.h"
#include <iostream>

int main() {

    std::string cmdline;
    PlayList* playList;

    // Waits for command from user
    while (1) {
        std::getline(std::cin, cmdline);

        // Set max songs in playlist
        if (cmdline[0] == 'm') {
            int listSize = cmdline[2] - 48;
            playList = new PlayList(listSize);
            std::cout << "success" << std::endl;
        }

        // adds song to playlist
        if (cmdline[0] == 'i') {
            // finds index of semi-colon
            int semi_colon = cmdline.find(';');

            // using index of semi-colon, the words before and after it can be saved
            std::string song = cmdline.substr(2, semi_colon - 2);
            std::string artist = cmdline.substr(semi_colon + 1, cmdline.length());

            // Will not add song if playlist is full or is already in
            if (playList->songCount >= playList->listSize || playList->duplicate(song, artist)) {
                std::cout << "can not insert " << song << ';' << artist << std::endl;
                continue;
            }

            // song library is updated with name and artist of song and added to playlist
            playList->addtoPlaylist(song, artist);
            std::cout << "success" << std::endl;
        }

        // plays song at position 'n'
        if (cmdline[0] == 'p') {

            // if 'n' is not in playlist range then error
            int index = cmdline[2] - 48;
            if (playList->songCount < index || index == 0) {
                std::cout << "can not play " << index << std::endl;
                continue;
            }

            // otherwise, play music at 'n'
            playList->playMusic(index);
        }

        // erase song at position 'n'
        if (cmdline[0] == 'e' && cmdline[0] == ' ') {

            // if 'n' is not in playlist range then error
            int index = cmdline[2] - 48;
            if (playList->songCount < index || index == 0) {
                std::cout << "can not erase " << index << std::endl;
                continue;
            }

            // erases song and shuffles the playlist down 1
            playList->erase(index);
            std::cout << "success" << std::endl;
        }

        // frees memory and ends program
        if (cmdline == "exit") {
            delete playList;
            break; 
        }
    }

    return 0;
}

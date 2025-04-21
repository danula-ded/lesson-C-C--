#include "media.h"
#include <iostream>
#include <memory>

int main() {
    MediaPlayer player;
    
    // Add different media items to the player
    player.addMedia(std::make_unique<Song>("Queen"));
    player.addMedia(std::make_unique<Video>("Matrix"));
    player.addMedia(std::make_unique<Song>("The Beatles"));
    player.addMedia(std::make_unique<Video>("Inception"));
    player.addMedia(std::make_unique<Song>("Pink Floyd"));
    
    // Play all media
    std::cout << "Playing all media:" << std::endl;
    player.playAll();
    
    return 0;
} 
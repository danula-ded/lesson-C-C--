#include "song.h"
#include "video.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    std::vector<std::unique_ptr<IPlayable>> media;

    // Add different types of media
    media.push_back(std::make_unique<Song>());
    media.push_back(std::make_unique<Video>());
    media.push_back(std::make_unique<Song>());
    media.push_back(std::make_unique<Video>());

    // Play all media
    std::cout << "Playing media:" << std::endl;
    for (const auto& item : media) {
        item->play();
    }

    return 0;
} 
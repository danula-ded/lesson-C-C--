#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Playable {
protected:
    std::string name;
public:
    Playable() : name("Playable") {}
    virtual ~Playable() {}
    virtual void play() = 0;
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
};

class Song : public Playable {
private:
    std::string artist;
public:
    Song(const std::string& artist) : artist(artist) {
        name = "Song";
    }
    void play() override {
        std::cout << "Играет песня исполнителя " << artist << std::endl;
    }
};

class Video : public Playable {
private:
    std::string title;
public:
    Video(const std::string& title) : title(title) {
        name = "Video";
    }
    void play() override {
        std::cout << "Воспроизводится видео: " << title << std::endl;
    }
};

class MediaPlayer {
private:
    std::vector<std::unique_ptr<Playable>> media;
public:
    void addMedia(std::unique_ptr<Playable> item) {
        media.push_back(std::move(item));
    }
    
    void playAll() {
        for (const auto& item : media) {
            item->play();
        }
    }
};

#endif // MEDIA_H 
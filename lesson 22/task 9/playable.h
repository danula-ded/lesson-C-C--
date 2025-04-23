#ifndef PLAYABLE_H
#define PLAYABLE_H

#include <iostream>

class IPlayable {
public:
    virtual void play() const = 0;
    virtual ~IPlayable() = default;
};

class Song : public IPlayable {
public:
    void play() const override {
        std::cout << "Играет песня" << std::endl;
    }
};

class Video : public IPlayable {
public:
    void play() const override {
        std::cout << "Играет видео" << std::endl;
    }
};

#endif // PLAYABLE_H 
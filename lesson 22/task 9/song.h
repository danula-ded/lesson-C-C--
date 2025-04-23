#ifndef SONG_H
#define SONG_H

#include "playable.h"

class Song : public IPlayable {
public:
    void play() const override;
};

#endif // SONG_H 
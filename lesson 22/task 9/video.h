#ifndef VIDEO_H
#define VIDEO_H

#include "playable.h"

class Video : public IPlayable {
public:
    void play() const override;
};

#endif // VIDEO_H 
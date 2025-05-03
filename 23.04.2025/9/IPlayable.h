#ifndef IPLAYABLE_H
#define IPLAYABLE_H

#include <iostream>

class IPlayable {
public:
    virtual void play() const = 0;
    virtual ~IPlayable() {}
};

#endif // IPLAYABLE_H 
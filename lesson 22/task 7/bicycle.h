#ifndef BICYCLE_H
#define BICYCLE_H

#include "vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle();
    void move() const override;
};

#endif // BICYCLE_H 
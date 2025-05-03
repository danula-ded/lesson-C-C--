#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    void move() const override;
};

#endif // BICYCLE_H 
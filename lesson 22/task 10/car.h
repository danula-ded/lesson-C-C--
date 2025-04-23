#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle {
public:
    Car();
    double fuelEfficiency() const override;
};

#endif // CAR_H 
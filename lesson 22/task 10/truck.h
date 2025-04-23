#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle {
public:
    Truck();
    double fuelEfficiency() const override;
};

#endif // TRUCK_H 
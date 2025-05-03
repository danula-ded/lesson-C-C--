#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    double fuelEfficiency() const override;
};

#endif // TRUCK_H 
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
public:
    virtual double fuelEfficiency() const = 0;
    virtual ~Vehicle() {}
};

#endif // VEHICLE_H 
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
public:
    virtual void move() const = 0;
    virtual ~Vehicle() {}
};

#endif // VEHICLE_H 
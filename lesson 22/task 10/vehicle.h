#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string name;
public:
    Vehicle(const std::string& n);
    virtual double fuelEfficiency() const = 0;
    virtual ~Vehicle() = default;
};

#endif // VEHICLE_H 
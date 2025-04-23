#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
public:
    virtual void move() const = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    void move() const override {
        std::cout << "Машина едет" << std::endl;
    }
};

class Bicycle : public Vehicle {
public:
    void move() const override {
        std::cout << "Велосипед едет" << std::endl;
    }
};

#endif // VEHICLE_H 
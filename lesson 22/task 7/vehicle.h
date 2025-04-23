#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string name;
public:
    Vehicle(const std::string& n);
    virtual void move() const;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    Car() : Vehicle("Машина") {}
    void move() const override {
        std::cout << "Машина едет" << std::endl;
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle() : Vehicle("Велосипед") {}
    void move() const override {
        std::cout << "Велосипед едет" << std::endl;
    }
};

#endif // VEHICLE_H 
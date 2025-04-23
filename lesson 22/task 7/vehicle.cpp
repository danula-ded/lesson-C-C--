#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string& n) : name(n) {}

void Vehicle::move() const {
    std::cout << name << " движется" << std::endl;
} 
#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(int speed) : speed(speed) {}

void Vehicle::displaySpeed() const {
    std::cout << "Speed: " << speed << " km/h" << std::endl;
} 
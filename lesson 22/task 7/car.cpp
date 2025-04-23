#include "car.h"
#include <iostream>

Car::Car() : Vehicle("Машина") {}

void Car::move() const {
    std::cout << "Машина едет" << std::endl;
} 
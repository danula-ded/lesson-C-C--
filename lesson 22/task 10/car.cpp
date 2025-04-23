#include "car.h"

Car::Car() : Vehicle("Car") {}

double Car::fuelEfficiency() const {
    return 15.0; // 15 km/l
} 
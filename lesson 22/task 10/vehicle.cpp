#include "vehicle.h"

Vehicle::Vehicle(const std::string& n) : name(n) {}

Car::Car() : Vehicle("Car") {}

double Car::fuelEfficiency() const {
    return 15.0; // 15 km/l
}

Truck::Truck() : Vehicle("Truck") {}

double Truck::fuelEfficiency() const {
    return 8.0; // 8 km/l
} 
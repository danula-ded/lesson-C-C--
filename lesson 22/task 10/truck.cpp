#include "truck.h"

Truck::Truck() : Vehicle("Truck") {}

double Truck::fuelEfficiency() const {
    return 8.0; // 8 km/l
} 
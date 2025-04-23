#include "bicycle.h"
#include <iostream>

Bicycle::Bicycle() : Vehicle("Велосипед") {}

void Bicycle::move() const {
    std::cout << "Велосипед едет" << std::endl;
} 
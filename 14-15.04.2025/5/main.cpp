#include "Car.h"
#include <iostream>

int main() {
    // Create a Car object with speed and power
    Car car(120, 150);
    
    // Display car properties
    std::cout << "Car properties:" << std::endl;
    car.displaySpeed();
    car.displayPower();
    
    return 0;
} 
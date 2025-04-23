#include "car.h"
#include "bicycle.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    // Create a vector of unique pointers to Vehicle
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    // Add vehicles to the vector
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Bicycle>());
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Bicycle>());

    // Move all vehicles using range-based for loop
    std::cout << "Moving all vehicles:" << std::endl;
    for (const auto& vehicle : vehicles) {
        vehicle->move();
    }

    return 0;
} 
#include "car.h"
#include "bicycle.h"
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    
    // Create vehicles
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Bicycle>());
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Bicycle>());

    // Make all vehicles move
    for (const auto& vehicle : vehicles) {
        vehicle->move();
    }

    return 0;
} 
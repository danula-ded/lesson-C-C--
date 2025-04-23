#include "car.h"
#include "truck.h"
#include <vector>
#include <memory>
#include <iomanip>
#include <iostream>
#include <typeinfo>

int main() {
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    // Add vehicles to the vector
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Truck>());
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Truck>());

    // Display fuel efficiency for each vehicle
    std::cout << "Fuel Efficiency Report:" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    for (const auto& vehicle : vehicles) {
        std::cout << "Vehicle type: " << typeid(*vehicle).name() 
                  << ", Efficiency: " << vehicle->fuelEfficiency() << " km/l" << std::endl;
    }

    return 0;
} 
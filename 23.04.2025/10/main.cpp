#include "Car.h"
#include "Truck.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<Vehicle*> vehicles;
    
    // Создаем объекты Car и Truck
    vehicles.push_back(new Car());
    vehicles.push_back(new Truck());
    
    // Выводим эффективность топлива для каждого транспортного средства
    for (const auto& vehicle : vehicles) {
        std::cout << "Эффективность топлива: " << vehicle->fuelEfficiency() << " км/л" << std::endl;
    }
    
    // Очистка памяти
    for (auto vehicle : vehicles) {
        delete vehicle;
    }
    
    return 0;
} 
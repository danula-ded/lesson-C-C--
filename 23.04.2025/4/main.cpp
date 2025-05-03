#include "Car.h"
#include "Bicycle.h"
#include <vector>

int main() {
    std::vector<Vehicle*> vehicles;
    
    // Создаем объекты Car и Bicycle
    vehicles.push_back(new Car());
    vehicles.push_back(new Bicycle());
    
    // Вызываем метод move() для каждого транспортного средства
    for (const auto& vehicle : vehicles) {
        vehicle->move();
    }
    
    // Очистка памяти
    for (auto vehicle : vehicles) {
        delete vehicle;
    }
    
    return 0;
} 
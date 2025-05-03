#include "Animal.h"
#include "Shape.h"
#include <iostream>
#include <vector>

int main() {
    // Демонстрация задания 1 и 2
    std::cout << "=== Демонстрация работы с животными ===" << std::endl;
    std::vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    
    for (const auto& animal : animals) {
        animal->speak();
        animal->info();
    }
    
    // Демонстрация задания 3
    std::cout << "\n=== Демонстрация работы с фигурами ===" << std::endl;
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    
    for (const auto& shape : shapes) {
        std::cout << "Площадь фигуры: " << shape->area() << std::endl;
    }
    
    // Очистка памяти
    for (auto animal : animals) {
        delete animal;
    }
    
    for (auto shape : shapes) {
        delete shape;
    }
    
    return 0;
} 
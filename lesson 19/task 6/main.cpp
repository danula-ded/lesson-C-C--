#include "animals.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    const int numAnimals = 5;
    std::vector<std::unique_ptr<Animal>> animals;
    
    // Create animals using the factory function
    animals.push_back(createAnimal("dog"));
    animals.push_back(createAnimal("cat"));
    animals.push_back(createAnimal("dog"));
    animals.push_back(createAnimal("cat"));
    animals.push_back(createAnimal("dog"));
    
    // Make all animals speak
    std::cout << "Making all animals speak:" << std::endl;
    for (const auto& animal : animals) {
        if (animal) {
            std::cout << animal->getName() << " says: ";
            animal->speak();
        }
    }
    
    return 0;
} 
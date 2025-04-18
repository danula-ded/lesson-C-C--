#include "animals.h"
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    
    for (const auto& animal : animals) {
        displayAnimal(animal.get());
    }
    
    return 0;
} 
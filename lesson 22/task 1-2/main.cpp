#include "animal.h"
#include <vector>

int main() {
    // Task 1: Array of Animal pointers
    std::cout << "Task 1: Array of Animal pointers" << std::endl;
    std::vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (const auto& animal : animals) {
        animal->speak();
    }

    // Task 2: Using override and final
    std::cout << "\nTask 2: Using override and final" << std::endl;
    Dog dog;
    Cat cat;

    dog.info();
    cat.info();

    // Clean up
    for (auto& animal : animals) {
        delete animal;
    }

    return 0;
} 
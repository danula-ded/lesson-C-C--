#include "Animal.h"
#include "Dog.h"
#include <iostream>

int main() {
    // Create Animal and Dog objects
    Animal animal("Generic", 3);
    Dog dog("Buddy", 5, "Labrador");

    // Demonstrate speaking
    std::cout << "Animal speaking:" << std::endl;
    animal.speak();
    std::cout << "\nDog speaking:" << std::endl;
    dog.speak();

    // Show memory addresses and sizes
    std::cout << "\nMemory information:" << std::endl;
    std::cout << "Animal object address: " << &animal << std::endl;
    std::cout << "Animal object size: " << sizeof(animal) << " bytes" << std::endl;
    std::cout << "Dog object address: " << &dog << std::endl;
    std::cout << "Dog object size: " << sizeof(dog) << " bytes" << std::endl;

    return 0;
} 
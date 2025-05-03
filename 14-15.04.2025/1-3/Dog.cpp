#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name, int age, const std::string& breed)
    : Animal(name, age), breed(breed) {}

void Dog::speak() const {
    std::cout << "Woof! Woof! I'm " << getName() << ", a " << breed << " dog!" << std::endl;
} 
#include "dog.h"
#include <iostream>

Dog::Dog(const std::string& name, int age, const std::string& breed) 
    : Animal(name, age), breed(breed) {}

void Dog::speak() const {
    std::cout << "Woof! My name is " << name << ", I'm " << age 
              << " years old and I'm a " << breed << "." << std::endl;
}
#include "cat.h"
#include <iostream>

Cat::Cat(const std::string& name, int age, const std::string& color) 
    : Animal(name, age), color(color) {}

void Cat::speak() const {
    std::cout << "Meow! I'm " << name << ", a " << age 
              << " years old " << color << " cat." << std::endl;
}
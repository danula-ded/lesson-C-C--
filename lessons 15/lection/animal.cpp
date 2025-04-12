#include "animal.h"
#include <iostream>

Animal::Animal(const std::string& name, int age) : name(name), age(age) {}

void Animal::speak() const {
    std::cout << "My name is " << name << " and I'm " << age << " years old." << std::endl;
}
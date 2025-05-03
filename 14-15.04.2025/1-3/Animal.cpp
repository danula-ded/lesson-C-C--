#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string& name, int age) : name(name), age(age) {}

std::string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

void Animal::speak() const {
    std::cout << "The animal makes a sound." << std::endl;
} 
#include "Derived.h"
#include <iostream>

void Derived::show() const {
    std::cout << "Это производный класс" << std::endl;
}

Derived::~Derived() {
    std::cout << "Derived destructor called" << std::endl;
} 
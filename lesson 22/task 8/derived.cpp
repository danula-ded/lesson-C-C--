#include "derived.h"
#include <iostream>

void Derived::show() const {
    std::cout << "Это производный класс" << std::endl;
}

Derived::~Derived() {
    std::cout << "Деструктор Derived" << std::endl;
} 
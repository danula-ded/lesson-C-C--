#include "base.h"
#include <iostream>

void Base::show() const {
    std::cout << "Это базовый класс" << std::endl;
}

Base::~Base() {
    std::cout << "Деструктор Base" << std::endl;
} 
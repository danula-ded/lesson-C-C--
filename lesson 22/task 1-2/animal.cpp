#include "animal.h"

// Animal class implementation
void Animal::speak() {
    std::cout << "Animal sound" << std::endl;
}

void Animal::info() {
    std::cout << "This is an animal" << std::endl;
}

// Dog class implementation
void Dog::speak() {
    std::cout << "Гав!" << std::endl;
}

void Dog::info() {
    std::cout << "Это собака" << std::endl;
}

// Cat class implementation
void Cat::speak() {
    std::cout << "Мяу!" << std::endl;
}

void Cat::info() {
    std::cout << "Это кошка" << std::endl;
} 
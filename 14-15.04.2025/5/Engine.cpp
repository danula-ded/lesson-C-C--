#include "Engine.h"
#include <iostream>

Engine::Engine(int power) : power(power) {}

void Engine::displayPower() const {
    std::cout << "Power: " << power << " HP" << std::endl;
} 
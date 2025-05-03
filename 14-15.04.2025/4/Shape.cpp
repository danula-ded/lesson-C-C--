#include "Shape.h"
#include <iostream>

Shape::Shape(const std::string& color) : color(color) {}

void Shape::displayColor() const {
    std::cout << "Color: " << color << std::endl;
} 
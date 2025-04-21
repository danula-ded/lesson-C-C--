#include "square.h"
#include <iostream>

Square::Square(double s) : side(s) {}

void Square::draw() {
    std::cout << "Drawing a Square" << std::endl;
}

double Square::getPerimeter() {
    return 4 * side;
}

double Square::getArea() {
    return side * side;
} 
#include "circle.h"
#include <iostream>
#include <cmath>

Circle::Circle(double r) : radius(r) {}

void Circle::draw() {
    std::cout << "Drawing a Circle" << std::endl;
}

double Circle::getPerimeter() {
    return 2 * M_PI * radius;
}

double Circle::getArea() {
    return M_PI * radius * radius;
} 
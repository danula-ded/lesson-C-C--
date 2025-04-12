#include "point.h"
#include <iostream>

Point::Point(double x, double y) : x(x), y(y) {}

void Point::display() const {
    std::cout << "Point coordinates: (" << x << ", " << y << ")" << std::endl;
}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
} 
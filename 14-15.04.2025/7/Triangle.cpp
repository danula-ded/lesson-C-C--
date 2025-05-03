#include "Triangle.h"

Triangle::Triangle(double b, double h) : base(b), height(h) {}

double Triangle::area() const {
    return 0.5 * base * height;
} 
#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(double s1, double s2, double s3) 
    : side1(s1), side2(s2), side3(s3) {}

void Triangle::draw() {
    std::cout << "Drawing a Triangle" << std::endl;
}

double Triangle::getPerimeter() {
    return side1 + side2 + side3;
}

double Triangle::getArea() {
    // Используем формулу Герона
    double p = getPerimeter() / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
} 
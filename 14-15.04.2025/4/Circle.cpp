#include "Circle.h"

Circle::Circle(const std::string& color) : Shape(color) {}

void Circle::setColor(const std::string& newColor) {
    color = newColor;
} 
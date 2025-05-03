#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(const std::string& color);
    void setColor(const std::string& newColor);
}; 
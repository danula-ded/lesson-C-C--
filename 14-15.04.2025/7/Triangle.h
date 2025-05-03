#pragma once
#include "Shape.h"

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h);
    double area() const override;
}; 
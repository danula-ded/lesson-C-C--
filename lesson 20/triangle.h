#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
private:
    double side1, side2, side3;  // Длины сторон треугольника
public:
    Triangle(double s1, double s2, double s3);
    void draw() override;
    double getPerimeter() override;
    double getArea() override;
};

#endif // TRIANGLE_H 
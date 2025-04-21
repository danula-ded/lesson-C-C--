#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r);
    void draw() override;
    double getPerimeter() override;
    double getArea() override;
};

#endif // CIRCLE_H 
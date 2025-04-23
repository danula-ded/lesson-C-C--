#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r);
    double area() const override;
};

#endif // CIRCLE_H 
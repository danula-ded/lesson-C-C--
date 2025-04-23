#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h);
    double area() const override;
};

#endif // RECTANGLE_H 
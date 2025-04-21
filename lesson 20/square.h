#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape {
private:
    double side;
public:
    Square(double s);
    void draw() override;
    double getPerimeter() override;
    double getArea() override;
};

#endif 
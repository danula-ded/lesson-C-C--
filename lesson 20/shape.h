#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual void draw() = 0;          // Pure virtual method
    virtual double getPerimeter() = 0; // Pure virtual method for perimeter
    virtual double getArea() = 0;      // Pure virtual method for area
    virtual ~Shape() {}               // Virtual destructor
};

#endif
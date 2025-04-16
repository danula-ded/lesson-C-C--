#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Shape {
public:
    virtual void display() const {
        std::cout << "Shape area: " << area() << std::endl;
    }
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    
    void display() const override {
        std::cout << "Circle with radius " << radius << ": ";
        Shape::display();
    }
    
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    void display() const override {
        std::cout << "Rectangle " << width << "x" << height << ": ";
        Shape::display();
    }
    
    double area() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    void display() const override {
        std::cout << "Triangle with base " << base << " and height " << height << ": ";
        Shape::display();
    }
    
    double area() const override {
        return 0.5 * base * height;
    }
};

void displayShape(const Shape* shape) {
    shape->display();
}

#endif // SHAPES_H 
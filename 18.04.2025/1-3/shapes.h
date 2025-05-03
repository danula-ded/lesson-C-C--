#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <iostream>

class Shape {
protected:
    std::string name;
public:
    Shape() : name("Shape") {}
    virtual ~Shape() {}
    virtual void draw() = 0;
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
};

class Circle : public Shape {
private:
    double radius;
    double area;
public:
    Circle(double r) : radius(r) {
        name = "Circle";
        calculateArea();
    }
    void draw() override {
        std::cout << "Рисуем круг" << std::endl;
    }
    void calculateArea() {
        area = 3.14159 * radius * radius;
    }
    double getArea() const { return area; }
};

class Square : public Shape {
private:
    double side;
    double area;
public:
    Square(double s) : side(s) {
        name = "Square";
        calculateArea();
    }
    void draw() override {
        std::cout << "Рисуем квадрат" << std::endl;
    }
    void calculateArea() {
        area = side * side;
    }
    double getArea() const { return area; }
};

#endif // SHAPES_H 
#ifndef SHAPES_H
#define SHAPES_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Shape {
protected:
    std::string name;
public:
    Shape() : name("Shape") {}
    virtual ~Shape() {}
    virtual void draw() = 0;
    virtual double getArea() = 0;
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {
        name = "Circle";
    }
    void draw() override {
        std::cout << "Рисуем круг" << std::endl;
    }
    double getArea() override {
        return 3.14159 * radius * radius;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {
        name = "Square";
    }
    void draw() override {
        std::cout << "Рисуем квадрат" << std::endl;
    }
    double getArea() override {
        return side * side;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {
        name = "Triangle";
    }
    void draw() override {
        std::cout << "Рисуем треугольник" << std::endl;
    }
    double getArea() override {
        return 0.5 * base * height;
    }
};

class ShapeCollection {
private:
    std::vector<std::unique_ptr<Shape>> shapes;
public:
    void addShape(std::unique_ptr<Shape> shape) {
        shapes.push_back(std::move(shape));
    }
    
    void drawAll() {
        for (const auto& shape : shapes) {
            shape->draw();
            std::cout << "Площадь: " << shape->getArea() << std::endl;
        }
    }
};

#endif // SHAPES_H 
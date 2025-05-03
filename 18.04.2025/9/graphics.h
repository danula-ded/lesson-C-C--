#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Graphic {
protected:
    std::string name;
public:
    Graphic() : name("Graphic") {}
    virtual ~Graphic() {}
    virtual void render() = 0;
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
};

class Line : public Graphic {
private:
    int x1, y1, x2, y2;
public:
    Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        name = "Line";
    }
    void render() override {
        std::cout << "Рисуем линию от (" << x1 << "," << y1 << ") до (" << x2 << "," << y2 << ")" << std::endl;
    }
};

class Rectangle : public Graphic {
private:
    int x, y, width, height;
public:
    Rectangle(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {
        name = "Rectangle";
    }
    void render() override {
        std::cout << "Рисуем прямоугольник в точке (" << x << "," << y << ") размером " 
                  << width << "x" << height << std::endl;
    }
};

class Triangle : public Graphic {
private:
    int x1, y1, x2, y2, x3, y3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) 
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
        name = "Triangle";
    }
    void render() override {
        std::cout << "Рисуем треугольник с вершинами (" << x1 << "," << y1 << "), (" 
                  << x2 << "," << y2 << "), (" << x3 << "," << y3 << ")" << std::endl;
    }
};

class GraphicEditor {
private:
    std::vector<std::unique_ptr<Graphic>> graphics;
public:
    void addGraphic(std::unique_ptr<Graphic> graphic) {
        graphics.push_back(std::move(graphic));
    }
    
    void renderAll() {
        for (const auto& graphic : graphics) {
            graphic->render();
        }
    }
};

#endif // GRAPHICS_H 
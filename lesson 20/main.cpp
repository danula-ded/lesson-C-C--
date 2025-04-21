#include "shape.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    // Создаем вектор указателей на Shape
    std::vector<Shape*> shapes;
    
    // Добавляем фигуры с конкретными размерами
    shapes.push_back(new Circle(5.0));      // Круг с радиусом 5
    shapes.push_back(new Square(4.0));      // Квадрат со стороной 4
    shapes.push_back(new Triangle(3.0, 4.0, 5.0)); // Треугольник со сторонами 3, 4, 5
    
    // Выводим информацию о каждой фигуре
    for (Shape* shape : shapes) {
        shape->draw();
        std::cout << "Perimeter: " << std::fixed << std::setprecision(2) 
                  << shape->getPerimeter() << std::endl;
        std::cout << "Area: " << std::fixed << std::setprecision(2) 
                  << shape->getArea() << std::endl;
        std::cout << std::endl;
    }
    
    // Очищаем память
    for (Shape* shape : shapes) {
        delete shape;
    }
    
    return 0;
} 
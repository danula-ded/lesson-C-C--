#include "shapes.h"
#include <iostream>
#include <vector>

// Function that takes a pointer to base class and calls draw()
void drawShape(Shape* shape) {
    shape->draw();
}

int main() {
    // Create objects
    Circle circle(5.0);
    Square square(4.0);

    // Demonstrate polymorphism through function
    std::cout << "Demonstrating polymorphism through function:" << std::endl;
    drawShape(&circle);
    drawShape(&square);
    std::cout << std::endl;

    // Create array of pointers to Shape
    const int numShapes = 4;
    Shape* shapes[numShapes];
    
    // Fill array with objects
    shapes[0] = new Circle(3.0);
    shapes[1] = new Square(2.0);
    shapes[2] = new Circle(4.0);
    shapes[3] = new Square(3.0);

    // Demonstrate array of pointers
    std::cout << "Demonstrating array of pointers:" << std::endl;
    for (int i = 0; i < numShapes; ++i) {
        shapes[i]->draw();
    }
    std::cout << std::endl;

    // Investigate object sizes
    std::cout << "Size investigation:" << std::endl;
    std::cout << "Size of Shape: " << sizeof(Shape) << " bytes" << std::endl;
    std::cout << "Size of Circle: " << sizeof(Circle) << " bytes" << std::endl;
    std::cout << "Size of Square: " << sizeof(Square) << " bytes" << std::endl;
    std::cout << std::endl;

    // Demonstrate area calculation
    std::cout << "Area demonstration:" << std::endl;
    for (int i = 0; i < numShapes; ++i) {
        if (Circle* c = dynamic_cast<Circle*>(shapes[i])) {
            std::cout << "Circle area: " << c->getArea() << std::endl;
        } else if (Square* s = dynamic_cast<Square*>(shapes[i])) {
            std::cout << "Square area: " << s->getArea() << std::endl;
        }
    }

    // Clean up
    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }

    return 0;
} 
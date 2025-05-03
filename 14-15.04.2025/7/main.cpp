#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <vector>

int main() {
    // Create a vector of Shape pointers
    std::vector<Shape*> shapes;
    
    // Add different shapes to the vector
    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Triangle(4.0, 6.0));
    shapes.push_back(new Rectangle(2.5, 4.0));
    shapes.push_back(new Triangle(3.0, 5.0));
    
    // Calculate and display areas
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }
    
    // Clean up
    for (auto& shape : shapes) {
        delete shape;
    }
    
    return 0;
} 
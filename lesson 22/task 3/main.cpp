#include "circle.h"
#include "rectangle.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    
    // Create some shapes
    shapes.push_back(std::make_unique<Circle>(5.0));    // Circle with radius 5
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));  // Rectangle 4x6
    shapes.push_back(std::make_unique<Circle>(3.0));    // Circle with radius 3
    shapes.push_back(std::make_unique<Rectangle>(2.0, 8.0));  // Rectangle 2x8

    // Calculate and display areas
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
    }

    return 0;
} 
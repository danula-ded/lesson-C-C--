#include "shapes.h"
#include <iostream>
#include <memory>

int main() {
    ShapeCollection collection;
    
    // Add different shapes to the collection
    collection.addShape(std::make_unique<Circle>(5.0));
    collection.addShape(std::make_unique<Square>(4.0));
    collection.addShape(std::make_unique<Triangle>(3.0, 4.0));
    collection.addShape(std::make_unique<Circle>(2.0));
    collection.addShape(std::make_unique<Square>(3.0));
    
    // Draw all shapes and show their areas
    std::cout << "Drawing all shapes and showing their areas:" << std::endl;
    collection.drawAll();
    
    return 0;
} 
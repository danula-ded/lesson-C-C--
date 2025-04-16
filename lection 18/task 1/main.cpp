#include "shapes.h"
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 4.0));
    
    for (const auto& shape : shapes) {
        displayShape(shape.get());
    }
    
    return 0;
} 
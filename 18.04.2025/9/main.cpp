#include "graphics.h"
#include <iostream>
#include <memory>

int main() {
    GraphicEditor editor;
    
    // Add different graphics to the editor
    editor.addGraphic(std::make_unique<Line>(0, 0, 100, 100));
    editor.addGraphic(std::make_unique<Rectangle>(50, 50, 200, 100));
    editor.addGraphic(std::make_unique<Triangle>(0, 0, 100, 0, 50, 100));
    editor.addGraphic(std::make_unique<Line>(200, 200, 300, 300));
    editor.addGraphic(std::make_unique<Rectangle>(150, 150, 100, 200));
    
    // Render all graphics
    std::cout << "Rendering all graphics:" << std::endl;
    editor.renderAll();
    
    return 0;
} 
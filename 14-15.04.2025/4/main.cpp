#include "Circle.h"
#include <iostream>

int main() {
    // Create a Circle object with initial color
    Circle circle("Red");
    
    // Display initial color
    std::cout << "Initial color: ";
    circle.displayColor();
    
    // Change the color
    circle.setColor("Blue");
    
    // Display new color
    std::cout << "New color: ";
    circle.displayColor();
    
    return 0;
} 
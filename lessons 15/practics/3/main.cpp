#include "rectangle.h"
#include <iostream>

int main() {
    Rectangle rect(5.0f, 3.0f);

    std::cout << "Rectangle Information:" << std::endl;
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Height: " << rect.getHeight() << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;

    rect.setWidth(7.0f);
    rect.setHeight(4.0f);

    std::cout << "\nUpdated Information:" << std::endl;
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Height: " << rect.getHeight() << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;

    return 0;
} 
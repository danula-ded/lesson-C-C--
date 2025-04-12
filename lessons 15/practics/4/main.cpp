#include "point.h"
#include <iostream>

int main() {
    Point p1(3.5, 4.2);
    
    std::cout << "Initial point:" << std::endl;
    p1.display();

    p1.move(2.1, -1.5);
    
    std::cout << "\nAfter moving:" << std::endl;
    p1.display();

    return 0;
} 
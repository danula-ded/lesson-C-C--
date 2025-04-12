#include "counter.h"
#include <iostream>

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "After creating c1: " << Counter::getCount() << std::endl;

    
    Counter c2;
    std::cout << "After creating c2: " << Counter::getCount() << std::endl;
    

    std::cout << "After c2 destruction: " << Counter::getCount() << std::endl;

    Counter* c3 = new Counter();
    std::cout << "After creating c3: " << Counter::getCount() << std::endl;

    delete c3;
    std::cout << "After deleting c3: " << Counter::getCount() << std::endl;

    return 0;
} 
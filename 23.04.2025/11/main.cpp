#include <iostream>
#include "Manager.h"
#include "Developer.h"

int main() {
    Manager manager(5000.0);
    Developer developer(4000.0);

    std::cout << "Manager salary: " << manager.calculateSalary() << std::endl;
    std::cout << "Developer salary: " << developer.calculateSalary() << std::endl;

    return 0;
} 
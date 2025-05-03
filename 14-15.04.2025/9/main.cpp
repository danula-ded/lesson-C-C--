#include "Manager.h"
#include <iostream>

int main() {
    // Create a manager
    Manager manager("John Smith", "IT");
    
    // Display initial information
    std::cout << "Manager Name: " << manager.getName() << std::endl;
    std::cout << "Department: " << manager.getDepartment() << std::endl;
    
    // Change department
    manager.setDepartment("Finance");
    
    // Display updated information
    std::cout << "\nAfter department change:" << std::endl;
    std::cout << "Manager Name: " << manager.getName() << std::endl;
    std::cout << "Department: " << manager.getDepartment() << std::endl;
    
    return 0;
} 
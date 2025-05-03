#include "Employee.h"
#include <iostream>

int main() {
    // Create an address
    Address addr("123 Main St", "New York", "10001");
    
    // Create an employee
    Employee emp("John Doe", addr, 12345);
    
    // Display employee information
    std::cout << "Employee Information:" << std::endl;
    std::cout << "Name: " << emp.getName() << std::endl;
    std::cout << "ID: " << emp.getEmployeeID() << std::endl;
    std::cout << "Address: " << emp.getAddress().getFullAddress() << std::endl;
    
    return 0;
} 
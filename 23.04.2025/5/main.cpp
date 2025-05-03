#include "Employee.h"
#include <iostream>

int main() {
    const double baseSalary = 1000.0;
    
    Manager manager(baseSalary);
    Developer developer(baseSalary);
    SeniorDeveloper seniorDeveloper(baseSalary);
    
    std::cout << "Зарплата менеджера: " << manager.getSalary() << std::endl;
    std::cout << "Зарплата разработчика: " << developer.getSalary() << std::endl;
    std::cout << "Зарплата старшего разработчика: " << seniorDeveloper.getSalary() << std::endl;
    
    return 0;
} 
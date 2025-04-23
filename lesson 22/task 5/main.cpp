#include "manager.h"
#include "developer.h"
#include "seniordeveloper.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    // Create employees with base salary of 1000
    Manager manager(1000);
    Developer developer(1000);
    SeniorDeveloper seniorDeveloper(1000);

    // Display salaries
    std::cout << "Manager salary: " << manager.getSalary() << std::endl;
    std::cout << "Developer salary: " << developer.getSalary() << std::endl;
    std::cout << "Senior Developer salary: " << seniorDeveloper.getSalary() << std::endl;

    // Demonstrate polymorphism
    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<Manager>(1000));
    employees.push_back(std::make_unique<Developer>(1000));
    employees.push_back(std::make_unique<SeniorDeveloper>(1000));

    std::cout << "\nSalaries through base class pointer:" << std::endl;
    for (const auto& employee : employees) {
        std::cout << "Salary: " << employee->getSalary() << std::endl;
    }

    return 0;
} 
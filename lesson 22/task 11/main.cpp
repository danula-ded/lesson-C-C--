#include "employee.h"
#include <vector>
#include <memory>
#include <iomanip>

int main() {
    // Create employees with base salary of 1000
    Manager manager(1000);
    Developer developer(1000);

    // Display individual salaries
    std::cout << "Individual Salary Report:" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Manager salary: $" << manager.calculateSalary() << std::endl;
    std::cout << "Developer salary: $" << developer.calculateSalary() << std::endl;

    // Demonstrate polymorphism
    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<Manager>(1000));
    employees.push_back(std::make_unique<Developer>(1000));

    std::cout << "\nSalary Report through base class pointers:" << std::endl;
    for (const auto& employee : employees) {
        std::cout << "Salary: $" << employee->calculateSalary() << std::endl;
    }

    return 0;
} 
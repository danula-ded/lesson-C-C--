#include "Employee.h"

Employee::Employee(const std::string& name) : name(name) {}

std::string Employee::getName() const {
    return name;
} 
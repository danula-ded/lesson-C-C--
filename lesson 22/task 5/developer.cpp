#include "developer.h"

Developer::Developer(double salary) : Employee(salary) {}

double Developer::getSalary() const {
    return baseSalary * 1.2; // Developers get 20% bonus
} 
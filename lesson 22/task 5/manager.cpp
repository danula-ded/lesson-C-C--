#include "manager.h"

Manager::Manager(double salary) : Employee(salary) {}

double Manager::getSalary() const {
    return baseSalary * 1.5; // Managers get 50% bonus
} 
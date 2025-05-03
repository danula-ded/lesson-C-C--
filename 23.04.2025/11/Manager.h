#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
    Manager(double salary) : Employee(salary) {}
    double calculateSalary() const override;
};

#endif // MANAGER_H 
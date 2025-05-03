#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee {
public:
    Developer(double salary) : Employee(salary) {}
    double calculateSalary() const override final;
};

#endif // DEVELOPER_H 
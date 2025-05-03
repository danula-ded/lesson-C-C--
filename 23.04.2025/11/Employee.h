#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
protected:
    double baseSalary;
public:
    Employee(double salary) : baseSalary(salary) {}
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
    double getBaseSalary() const { return baseSalary; }
};

#endif // EMPLOYEE_H 
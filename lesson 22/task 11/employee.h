#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
protected:
    double baseSalary;
public:
    Employee(double salary) : baseSalary(salary) {}
    virtual double calculateSalary() const {
        return baseSalary;
    }
    virtual ~Employee() = default;
};

class Manager : public Employee {
public:
    Manager(double salary) : Employee(salary) {}
    double calculateSalary() const override {
        return baseSalary * 1.2; // 20% bonus
    }
};

class Developer : public Employee {
public:
    Developer(double salary) : Employee(salary) {}
    double calculateSalary() const final override {
        return baseSalary * 1.1; // 10% bonus
    }
};

// This class will cause a compilation error because Developer::calculateSalary is final
/*
class SeniorDeveloper : public Developer {
public:
    SeniorDeveloper(double salary) : Developer(salary) {}
    double calculateSalary() const override { // Error: cannot override final method
        return baseSalary * 1.3; // 30% bonus
    }
};
*/

#endif // EMPLOYEE_H 
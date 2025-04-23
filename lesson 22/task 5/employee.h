#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
protected:
    double baseSalary;
public:
    Employee(double salary);
    virtual double getSalary() const;
    virtual ~Employee() = default;
};

class Manager : public Employee {
public:
    Manager(double salary) : Employee(salary) {}
    double getSalary() const final override {
        return baseSalary * 1.5; // Managers get 50% bonus
    }
};

class Developer : public Employee {
public:
    Developer(double salary) : Employee(salary) {}
    double getSalary() const override {
        return baseSalary * 1.2; // Developers get 20% bonus
    }
};

class SeniorDeveloper : public Developer {
public:
    SeniorDeveloper(double salary) : Developer(salary) {}
    double getSalary() const override {
        return baseSalary * 1.4; // Senior developers get 40% bonus
    }
};

#endif // EMPLOYEE_H 
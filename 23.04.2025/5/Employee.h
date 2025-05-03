#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
protected:
    double salary;
public:
    Employee(double s) : salary(s) {}
    virtual double getSalary() const = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    Manager(double s) : Employee(s) {}
    double getSalary() const override final {
        return salary * 1.5; // Менеджер получает на 50% больше
    }
};

class Developer : public Employee {
public:
    Developer(double s) : Employee(s) {}
    double getSalary() const override {
        return salary * 1.2; // Разработчик получает на 20% больше
    }
};

class SeniorDeveloper : public Developer {
public:
    SeniorDeveloper(double s) : Developer(s) {}
    double getSalary() const override {
        return salary * 1.4; // Старший разработчик получает на 40% больше
    }
};

#endif // EMPLOYEE_H 
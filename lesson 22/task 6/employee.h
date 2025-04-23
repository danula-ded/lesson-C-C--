#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
public:
    virtual void work() const;
    virtual ~Employee() = default;
};

class Manager : public Employee {
public:
    void work() const final override {
        std::cout << "Управляю" << std::endl;
    }
};

class Intern : public Employee {
public:
    void work() const override {
        std::cout << "Стажируюсь" << std::endl;
    }
};

// This class will cause a compilation error because Manager::work is final
/*
class JuniorManager : public Manager {
public:
    void work() const override { // Error: cannot override final method
        std::cout << "Учусь управлять" << std::endl;
    }
};
*/

#endif // EMPLOYEE_H 
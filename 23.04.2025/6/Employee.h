#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
public:
    virtual void work() const = 0;
    virtual ~Employee() {}
};

#endif // EMPLOYEE_H 
#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee {
public:
    Manager(double salary);
    double getSalary() const final override;
};

#endif // MANAGER_H 
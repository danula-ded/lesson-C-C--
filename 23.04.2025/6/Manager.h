#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
    void work() const override final;
};

#endif // MANAGER_H 
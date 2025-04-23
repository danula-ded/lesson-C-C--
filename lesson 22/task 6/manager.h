#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

class Manager : public Employee {
public:
    void work() const final override;
};

#endif // MANAGER_H 
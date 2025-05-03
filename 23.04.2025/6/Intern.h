#ifndef INTERN_H
#define INTERN_H

#include "Employee.h"

class Intern : public Employee {
public:
    void work() const override;
};

#endif // INTERN_H 
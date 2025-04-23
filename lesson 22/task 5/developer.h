#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "employee.h"

class Developer : public Employee {
public:
    Developer(double salary);
    double getSalary() const override;
};

#endif // DEVELOPER_H 
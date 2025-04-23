#ifndef SENIORDEVELOPER_H
#define SENIORDEVELOPER_H

#include "developer.h"

class SeniorDeveloper : public Developer {
public:
    SeniorDeveloper(double salary);
    double getSalary() const override;
};

#endif // SENIORDEVELOPER_H 
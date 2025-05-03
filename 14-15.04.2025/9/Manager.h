#pragma once
#include "Employee.h"
#include <string>

class Manager : public Employee {
private:
    std::string department;

public:
    Manager(const std::string& name, const std::string& dept);
    void setDepartment(const std::string& dept);
    std::string getDepartment() const;
}; 
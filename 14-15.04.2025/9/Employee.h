#pragma once
#include <string>

class Employee {
protected:
    std::string name;

public:
    Employee(const std::string& name);
    std::string getName() const;
}; 
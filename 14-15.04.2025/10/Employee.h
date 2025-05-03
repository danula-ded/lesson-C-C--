#pragma once
#include "Person.h"
#include <string>

class Employee : public Person {
private:
    int employeeID;

public:
    Employee(const std::string& name, const Address& addr, int id);
    int getEmployeeID() const;
}; 
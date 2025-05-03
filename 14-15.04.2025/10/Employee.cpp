#include "Employee.h"

Employee::Employee(const std::string& name, const Address& addr, int id)
    : Person(name, addr), employeeID(id) {}

int Employee::getEmployeeID() const {
    return employeeID;
} 
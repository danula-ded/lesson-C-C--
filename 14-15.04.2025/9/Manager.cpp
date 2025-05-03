#include "Manager.h"

Manager::Manager(const std::string& name, const std::string& dept)
    : Employee(name), department(dept) {}

void Manager::setDepartment(const std::string& dept) {
    department = dept;
}

std::string Manager::getDepartment() const {
    return department;
} 
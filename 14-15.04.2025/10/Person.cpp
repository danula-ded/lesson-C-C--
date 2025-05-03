#include "Person.h"

Person::Person(const std::string& name, const Address& addr)
    : name(name), address(addr) {}

std::string Person::getName() const {
    return name;
}

Address Person::getAddress() const {
    return address;
} 
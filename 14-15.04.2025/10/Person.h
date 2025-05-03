#pragma once
#include "Address.h"
#include <string>

class Person {
private:
    std::string name;
    Address address;

public:
    Person(const std::string& name, const Address& addr);
    std::string getName() const;
    Address getAddress() const;
}; 
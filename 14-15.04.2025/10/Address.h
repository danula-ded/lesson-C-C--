#pragma once
#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string zipCode;

public:
    Address(const std::string& street, const std::string& city, const std::string& zip);
    std::string getFullAddress() const;
}; 
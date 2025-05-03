#include "Address.h"

Address::Address(const std::string& street, const std::string& city, const std::string& zip)
    : street(street), city(city), zipCode(zip) {}

std::string Address::getFullAddress() const {
    return street + ", " + city + ", " + zipCode;
} 
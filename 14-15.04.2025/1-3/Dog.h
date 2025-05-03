#pragma once
#include "Animal.h"
#include <string>

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& breed);
    void speak() const override;
}; 
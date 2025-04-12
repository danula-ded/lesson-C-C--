#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include <string>

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& name, int age, const std::string& breed);
    void speak() const override;
};

#endif
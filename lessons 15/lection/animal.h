#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(const std::string& name, int age);
    virtual ~Animal() = default;
    virtual void speak() const;
};

#endif
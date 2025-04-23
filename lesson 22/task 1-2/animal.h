#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

// Base class Animal
class Animal {
public:
    virtual void speak();
    virtual void info();
    virtual ~Animal() = default;
};

// Derived class Dog
class Dog : public Animal {
public:
    void speak() override;
    void info() override;
};

// Derived class Cat
class Cat : public Animal {
public:
    void speak() override;
    void info() final;
};

#endif // ANIMAL_H 
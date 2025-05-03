#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
public:
    virtual void speak() const = 0;
    virtual void info() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Гав!" << std::endl;
    }
    
    void info() const override {
        std::cout << "Это собака" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Мяу!" << std::endl;
    }
    
    void info() const override final {
        std::cout << "Это кошка" << std::endl;
    }
};

#endif // ANIMAL_H 
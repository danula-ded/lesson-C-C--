#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
public:
    virtual void show() const;
    virtual ~Base();
};

class Derived : public Base {
public:
    void show() const override {
        std::cout << "Это производный класс" << std::endl;
    }
    
    ~Derived() override {
        std::cout << "Деструктор Derived" << std::endl;
    }
};

#endif // BASE_H 
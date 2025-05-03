#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
public:
    virtual void show() const = 0;
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

#endif // BASE_H 
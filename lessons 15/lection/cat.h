#ifndef CAT_H
#define CAT_H

#include "animal.h"
#include <string>

class Cat : public Animal {
private:
    std::string color;

public:
    Cat(const std::string& name, int age, const std::string& color);
    void speak() const override;
};

#endif
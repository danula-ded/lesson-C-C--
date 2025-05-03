#ifndef DERIVED_H
#define DERIVED_H

#include "Base.h"

class Derived : public Base {
public:
    void show() const override;
    ~Derived() override;
};

#endif // DERIVED_H 
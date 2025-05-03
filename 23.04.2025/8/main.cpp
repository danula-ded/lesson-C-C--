#include "Derived.h"
#include <iostream>

int main() {
    Base* basePtr = new Derived();
    basePtr->show();
    delete basePtr;
    return 0;
} 
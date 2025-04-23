#include "derived.h"
#include <memory>
#include <iostream>

int main() {
    std::cout << "Creating Derived object through Base pointer..." << std::endl;
    {
        Base* ptr = new Derived();
        ptr->show();
        std::cout << "Deleting object..." << std::endl;
        delete ptr;
    }

    std::cout << "\nUsing smart pointer..." << std::endl;
    {
        std::unique_ptr<Base> smart_ptr = std::make_unique<Derived>();
        smart_ptr->show();
        std::cout << "Smart pointer going out of scope..." << std::endl;
    }

    return 0;
} 
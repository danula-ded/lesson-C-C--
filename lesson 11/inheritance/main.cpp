#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!\n";
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak();
    a2->speak();

    delete a1;
    delete a2;
    return 0;
}

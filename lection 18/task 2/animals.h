#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Animal {
public:
    virtual void display() const {
        std::cout << "Animal sound: ";
        sound();
    }
    virtual void sound() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void display() const override {
        std::cout << "Dog says: ";
        Animal::display();
    }
    
    void sound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void display() const override {
        std::cout << "Cat says: ";
        Animal::display();
    }
    
    void sound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void displayAnimal(const Animal* animal) {
    animal->display();
}

#endif // ANIMALS_H 
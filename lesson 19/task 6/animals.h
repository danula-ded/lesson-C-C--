#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <iostream>
#include <memory>

class Animal {
protected:
    std::string name;
public:
    Animal() : name("Animal") {}
    virtual ~Animal() {}
    virtual void speak() = 0;
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
};

class Dog : public Animal {
public:
    Dog() {
        name = "Dog";
    }
    void speak() override {
        std::cout << "Гав-гав!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        name = "Cat";
    }
    void speak() override {
        std::cout << "Мяу!" << std::endl;
    }
};

// Factory function to create animals
std::unique_ptr<Animal> createAnimal(const std::string& type) {
    if (type == "dog") {
        return std::make_unique<Dog>();
    } else if (type == "cat") {
        return std::make_unique<Cat>();
    }
    return nullptr;
}

#endif // ANIMALS_H 
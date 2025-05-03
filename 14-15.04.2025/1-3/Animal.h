#pragma once
#include <string>

class Animal {
protected:
    int age;
private:
    std::string name;

public:
    Animal(const std::string& name, int age);
    virtual ~Animal() = default;
    
    // Getters
    std::string getName() const;
    int getAge() const;
    
    // Virtual method for speaking
    virtual void speak() const;
}; 
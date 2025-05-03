#pragma once
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age);
}; 
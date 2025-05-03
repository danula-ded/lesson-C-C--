#pragma once
#include "Person.h"

class Student : public Person {
private:
    int studentID;

public:
    Student(const std::string& name, int age, int studentID);
}; 
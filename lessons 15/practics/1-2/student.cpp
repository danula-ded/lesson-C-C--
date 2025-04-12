#include "student.h"
#include <iostream>

Student::Student(const std::string& name, int age, float gpa)
    : name(name), age(age), gpa(gpa) {}

void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setGpa(float gpa) {
    this->gpa = gpa;
}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

float Student::getGpa() const {
    return gpa;
}

void Student::displayInfo() const {
    std::cout << "Student Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
} 
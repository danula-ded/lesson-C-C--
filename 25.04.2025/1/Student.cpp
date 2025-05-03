#include "Student.h"

Student::Student(const std::string& name, int age, const std::string& group)
    : name(name), age(age), group(group) {}

void Student::displayInfo() const {
    std::cout << "Name: " << name << ", Age: " << age << ", Group: " << group << std::endl;
}

const std::string& Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

const std::string& Student::getGroup() const {
    return group;
} 
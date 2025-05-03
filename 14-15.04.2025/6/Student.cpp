#include "Student.h"

Student::Student(const std::string& name, int age, int studentID)
    : Person(name, age), studentID(studentID) {} 
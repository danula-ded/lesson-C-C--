#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int age;
    std::string group;
public:
    Student() : name(""), age(0), group("") {} // Конструктор по умолчанию
    Student(const std::string& name, int age, const std::string& group);
    void displayInfo() const;
    const std::string& getName() const;
    int getAge() const;
    const std::string& getGroup() const;
};

#endif // STUDENT_H 
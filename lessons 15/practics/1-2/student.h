#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int age;
    float gpa;

public:
    Student(const std::string& name, int age, float gpa);

    void setName(const std::string& name);
    void setAge(int age);
    void setGpa(float gpa);

    std::string getName() const;
    int getAge() const;
    float getGpa() const;

    void displayInfo() const;
};

#endif // STUDENT_H 
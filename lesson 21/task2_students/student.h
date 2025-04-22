#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;
    std::vector<double> grades;

public:
    Student() : name(""), id(0) {} // Default constructor
    Student(const std::string& name, int id);
    void addGrade(double grade);
    double getAverageGrade() const;
    void display() const;
    int getId() const;
};

#endif // STUDENT_H 
#include "student.h"
#include <iostream>
#include <numeric>

Student::Student(const std::string& name, int id) : name(name), id(id) {}

void Student::addGrade(double grade) {
    grades.push_back(grade);
}

double Student::getAverageGrade() const {
    if (grades.empty()) {
        return 0.0;
    }
    return std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
}

void Student::display() const {
    std::cout << "Student ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Grades: ";
    
    if (grades.empty()) {
        std::cout << "No grades yet";
    } else {
        for (double grade : grades) {
            std::cout << grade << " ";
        }
    }
    
    std::cout << "\nAverage Grade: " << getAverageGrade() << "\n"
              << "------------------------\n";
}

int Student::getId() const {
    return id;
} 
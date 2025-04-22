#include "student_manager.h"
#include <iostream>

void StudentManager::addStudent(const Student& student) {
    students[student.getId()] = student;
}

void StudentManager::removeStudent(int id) {
    students.erase(id);
}

void StudentManager::addGrade(int id, double grade) {
    auto it = students.find(id);
    if (it != students.end()) {
        it->second.addGrade(grade);
    }
}

void StudentManager::displayStudent(int id) const {
    auto it = students.find(id);
    if (it != students.end()) {
        it->second.display();
    } else {
        std::cout << "Student with ID " << id << " not found.\n";
    }
}

void StudentManager::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students in the system.\n";
        return;
    }

    std::cout << "All Students:\n";
    for (const auto& pair : students) {
        pair.second.display();
    }
}

double StudentManager::getOverallAverage() const {
    if (students.empty()) {
        return 0.0;
    }

    double total = 0.0;
    int count = 0;
    for (const auto& pair : students) {
        total += pair.second.getAverageGrade();
        count++;
    }
    return total / count;
} 
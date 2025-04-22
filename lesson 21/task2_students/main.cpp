#include "student_manager.h"
#include <iostream>

int main() {
    StudentManager manager;

    // Adding students
    manager.addStudent(Student("John Doe", 1));
    manager.addStudent(Student("Jane Smith", 2));
    manager.addStudent(Student("Bob Johnson", 3));

    // Adding grades
    manager.addGrade(1, 85.5);
    manager.addGrade(1, 90.0);
    manager.addGrade(2, 95.0);
    manager.addGrade(2, 88.5);
    manager.addGrade(3, 75.0);
    manager.addGrade(3, 82.5);

    // Display all students
    std::cout << "Initial student list:\n";
    manager.displayAllStudents();

    // Display overall average
    std::cout << "\nOverall average grade: " << manager.getOverallAverage() << "\n";

    // Remove a student
    std::cout << "\nRemoving student with ID 2...\n";
    manager.removeStudent(2);

    // Display students after removal
    std::cout << "\nStudent list after removal:\n";
    manager.displayAllStudents();

    return 0;
} 
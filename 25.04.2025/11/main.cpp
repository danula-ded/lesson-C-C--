#include "student_manager.h"
#include <iostream>
#include <limits>
#include <iomanip>

void printMenu() {
    std::cout << "\nStudent Management System Menu:\n"
              << "1. Load students from file\n"
              << "2. Search students by name\n"
              << "3. Filter students by average score\n"
              << "4. Show all students\n"
              << "5. Exit\n"
              << "Enter your choice: ";
}

void printStudentHeader() {
    std::cout << std::setw(20) << std::left << "Name"
              << std::setw(6) << std::right << "Age"
              << std::setw(8) << "Score" << "\n"
              << std::string(34, '-') << "\n";
}

void printStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }
    
    printStudentHeader();
    for (const auto& student : students) {
        std::cout << student.toString() << "\n";
    }
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    StudentManager manager;
    
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                std::string filename;
                std::cout << "Enter filename to load students from: ";
                std::getline(std::cin, filename);
                
                if (manager.loadFromFile(filename)) {
                    std::cout << "Students loaded successfully.\n";
                } else {
                    std::cout << "Failed to load students from file.\n";
                }
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter name to search: ";
                std::getline(std::cin, name);
                
                auto students = manager.findByName(name);
                std::cout << "\nSearch results:\n";
                printStudents(students);
                break;
            }
            case 3: {
                double minScore;
                std::cout << "Enter minimum average score: ";
                std::cin >> minScore;
                clearInputBuffer();
                
                auto students = manager.filterByAverageScore(minScore);
                std::cout << "\nStudents with score >= " << minScore << ":\n";
                printStudents(students);
                break;
            }
            case 4: {
                auto students = manager.getAllStudents();
                std::cout << "\nAll students:\n";
                printStudents(students);
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
} 
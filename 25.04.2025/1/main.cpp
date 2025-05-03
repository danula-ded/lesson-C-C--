#include <iostream>
#include <unordered_map>
#include <string>
#include <locale>
#include "Student.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::locale::global(std::locale("ru_RU.UTF-8"));
    
    std::unordered_map<int, Student> students;
    
    // Добавление студентов
    students[1] = Student("Ivan Ivanov", 20, "CS-101");
    students[2] = Student("Petr Petrov", 21, "CS-102");
    students[3] = Student("Anna Sidorova", 19, "CS-101");
    
    // Вывод всех студентов
    std::cout << "All students:" << std::endl;
    for (const auto& pair : students) {
        std::cout << "ID: " << pair.first << " - ";
        pair.second.displayInfo();
    }
    
    // Поиск студента
    int searchId = 2;
    auto it = students.find(searchId);
    if (it != students.end()) {
        std::cout << "\nFound student with ID " << searchId << ":" << std::endl;
        it->second.displayInfo();
    } else {
        std::cout << "\nStudent with ID " << searchId << " not found" << std::endl;
    }
    
    // Удаление студента
    int deleteId = 1;
    students.erase(deleteId);
    std::cout << "\nAfter deleting student with ID " << deleteId << ":" << std::endl;
    for (const auto& pair : students) {
        std::cout << "ID: " << pair.first << " - ";
        pair.second.displayInfo();
    }
    
    return 0;
} 
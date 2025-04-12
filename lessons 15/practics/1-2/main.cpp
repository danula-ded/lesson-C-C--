#include "student.h"
#include <iostream>

int main() {
    Student student("John Doe", 20, 3.8);

    student.displayInfo();

    student.setName("Jane Smith");
    student.setAge(21);
    student.setGpa(4.0);

    std::cout << "\nUpdated Information:" << std::endl;
    student.displayInfo();

    std::cout << "\nUsing getters:" << std::endl;
    std::cout << "Name: " << student.getName() << std::endl;
    std::cout << "Age: " << student.getAge() << std::endl;
    std::cout << "GPA: " << student.getGpa() << std::endl;

    return 0;
} 
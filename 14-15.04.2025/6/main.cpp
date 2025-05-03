#include "Person.h"
#include "Student.h"
#include <iostream>

int main() {
    // Create objects
    Person person("John", 25);
    Student student("Alice", 20, 12345);
    
    // Display sizes
    std::cout << "Size of Person object: " << sizeof(person) << " bytes" << std::endl;
    std::cout << "Size of Student object: " << sizeof(student) << " bytes" << std::endl;
    
    return 0;
} 
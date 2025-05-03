#pragma once
#include <string>

class Student {
public:
    Student(const std::string& name, int age, double averageScore);
    
    // Геттеры
    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getAverageScore() const { return averageScore; }
    
    // Для вывода информации о студенте
    std::string toString() const;
    
private:
    std::string name;
    int age;
    double averageScore;
}; 
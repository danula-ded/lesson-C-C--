#pragma once
#include "student.h"
#include <vector>
#include <string>

class StudentManager {
public:
    // Загрузка данных из файла
    bool loadFromFile(const std::string& filename);
    
    // Поиск студентов по имени
    std::vector<Student> findByName(const std::string& name) const;
    
    // Фильтрация студентов по среднему баллу
    std::vector<Student> filterByAverageScore(double minScore) const;
    
    // Получение всех студентов
    const std::vector<Student>& getAllStudents() const { return students; }
    
private:
    std::vector<Student> students;
}; 
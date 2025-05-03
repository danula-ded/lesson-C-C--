#include "student_manager.h"
#include <fstream>
#include <algorithm>

bool StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    students.clear();
    std::string name;
    int age;
    double score;
    
    while (file >> name >> age >> score) {
        students.emplace_back(name, age, score);
    }
    
    return true;
}

std::vector<Student> StudentManager::findByName(const std::string& name) const {
    std::vector<Student> result;
    
    std::copy_if(students.begin(), students.end(), std::back_inserter(result),
                 [&name](const Student& s) {
                     return s.getName().find(name) != std::string::npos;
                 });
    
    return result;
}

std::vector<Student> StudentManager::filterByAverageScore(double minScore) const {
    std::vector<Student> result;
    
    std::copy_if(students.begin(), students.end(), std::back_inserter(result),
                 [minScore](const Student& s) {
                     return s.getAverageScore() >= minScore;
                 });
    
    return result;
} 
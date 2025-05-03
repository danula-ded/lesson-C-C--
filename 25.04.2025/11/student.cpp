#include "student.h"
#include <sstream>
#include <iomanip>

Student::Student(const std::string& name, int age, double averageScore)
    : name(name), age(age), averageScore(averageScore) {}

std::string Student::toString() const {
    std::ostringstream oss;
    oss << std::setw(20) << std::left << name
        << std::setw(6) << std::right << age
        << std::setw(8) << std::fixed << std::setprecision(2) << averageScore;
    return oss.str();
} 
#pragma once
#include <string>
#include <vector>
#include <random>

class PasswordGenerator {
public:
    PasswordGenerator();
    
    // Генерация пароля с заданными параметрами
    std::string generatePassword(int length, bool useLetters, bool useNumbers, bool useSpecial);
    
private:
    std::mt19937 rng;
    
    // Вспомогательные методы
    std::string getLetters() const;
    std::string getNumbers() const;
    std::string getSpecialChars() const;
    char getRandomChar(const std::string& chars);
}; 
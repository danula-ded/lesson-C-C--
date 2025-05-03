#include "password_generator.h"
#include <algorithm>

PasswordGenerator::PasswordGenerator() {
    std::random_device rd;
    rng.seed(rd());
}

std::string PasswordGenerator::generatePassword(int length, bool useLetters, bool useNumbers, bool useSpecial) {
    std::string chars;
    if (useLetters) chars += getLetters();
    if (useNumbers) chars += getNumbers();
    if (useSpecial) chars += getSpecialChars();
    
    if (chars.empty()) {
        return "Error: No character sets selected";
    }
    
    std::string password;
    password.reserve(length);
    
    // Гарантируем, что пароль содержит хотя бы один символ из каждого выбранного набора
    if (useLetters) password += getRandomChar(getLetters());
    if (useNumbers) password += getRandomChar(getNumbers());
    if (useSpecial) password += getRandomChar(getSpecialChars());
    
    // Заполняем оставшуюся часть пароля случайными символами
    while (password.length() < length) {
        password += getRandomChar(chars);
    }
    
    // Перемешиваем символы пароля
    std::shuffle(password.begin(), password.end(), rng);
    
    return password;
}

std::string PasswordGenerator::getLetters() const {
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

std::string PasswordGenerator::getNumbers() const {
    return "0123456789";
}

std::string PasswordGenerator::getSpecialChars() const {
    return "!@#$%^&*()_+-=[]{}|;:,.<>?";
}

char PasswordGenerator::getRandomChar(const std::string& chars) {
    std::uniform_int_distribution<size_t> dist(0, chars.length() - 1);
    return chars[dist(rng)];
} 
#pragma once
#include <string>
#include <stack>
#include <vector>
#include <map>

class Calculator {
public:
    Calculator();
    
    // Основной метод для вычисления выражения
    double calculate(const std::string& expression);
    
private:
    // Структура для хранения токенов
    struct Token {
        enum class Type { NUMBER, OPERATOR, LEFT_PAREN, RIGHT_PAREN };
        Type type;
        std::string value;
        
        Token(Type t, const std::string& v) : type(t), value(v) {}
    };
    
    // Приоритеты операторов
    std::map<char, int> operatorPrecedence;
    
    // Вспомогательные методы
    std::vector<Token> tokenize(const std::string& expression);
    bool isOperator(char c) const;
    double applyOperator(double a, double b, char op) const;
    bool isDigit(char c) const;
    bool isSpace(char c) const;
}; 
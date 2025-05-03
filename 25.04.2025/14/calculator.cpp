#include "calculator.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

Calculator::Calculator() {
    // Инициализация приоритетов операторов
    operatorPrecedence['+'] = 1;
    operatorPrecedence['-'] = 1;
    operatorPrecedence['*'] = 2;
    operatorPrecedence['/'] = 2;
}

double Calculator::calculate(const std::string& expression) {
    std::vector<Token> tokens = tokenize(expression);
    std::stack<double> values;
    std::stack<char> operators;
    
    for (const auto& token : tokens) {
        if (token.type == Token::Type::NUMBER) {
            values.push(std::stod(token.value));
        }
        else if (token.type == Token::Type::LEFT_PAREN) {
            operators.push('(');
        }
        else if (token.type == Token::Type::RIGHT_PAREN) {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                
                if (values.size() < 2) {
                    throw std::runtime_error("Неверное выражение");
                }
                
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                values.push(applyOperator(a, b, op));
            }
            
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        }
        else if (token.type == Token::Type::OPERATOR) {
            char op = token.value[0];
            
            while (!operators.empty() && operators.top() != '(' &&
                   operatorPrecedence[operators.top()] >= operatorPrecedence[op]) {
                char prevOp = operators.top();
                operators.pop();
                
                if (values.size() < 2) {
                    throw std::runtime_error("Неверное выражение");
                }
                
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                values.push(applyOperator(a, b, prevOp));
            }
            
            operators.push(op);
        }
    }
    
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        
        if (op == '(') {
            throw std::runtime_error("Несбалансированные скобки");
        }
        
        if (values.size() < 2) {
            throw std::runtime_error("Неверное выражение");
        }
        
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        values.push(applyOperator(a, b, op));
    }
    
    if (values.size() != 1) {
        throw std::runtime_error("Неверное выражение");
    }
    
    return values.top();
}

std::vector<Calculator::Token> Calculator::tokenize(const std::string& expression) {
    std::vector<Token> tokens;
    std::string currentNumber;
    
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (isSpace(c)) {
            if (!currentNumber.empty()) {
                tokens.emplace_back(Token::Type::NUMBER, currentNumber);
                currentNumber.clear();
            }
            continue;
        }
        
        if (isDigit(c) || c == '.') {
            currentNumber += c;
        }
        else if (isOperator(c)) {
            if (!currentNumber.empty()) {
                tokens.emplace_back(Token::Type::NUMBER, currentNumber);
                currentNumber.clear();
            }
            tokens.emplace_back(Token::Type::OPERATOR, std::string(1, c));
        }
        else if (c == '(') {
            if (!currentNumber.empty()) {
                tokens.emplace_back(Token::Type::NUMBER, currentNumber);
                currentNumber.clear();
            }
            tokens.emplace_back(Token::Type::LEFT_PAREN, "(");
        }
        else if (c == ')') {
            if (!currentNumber.empty()) {
                tokens.emplace_back(Token::Type::NUMBER, currentNumber);
                currentNumber.clear();
            }
            tokens.emplace_back(Token::Type::RIGHT_PAREN, ")");
        }
        else {
            throw std::runtime_error("Неизвестный символ в выражении: " + std::string(1, c));
        }
    }
    
    if (!currentNumber.empty()) {
        tokens.emplace_back(Token::Type::NUMBER, currentNumber);
    }
    
    return tokens;
}

bool Calculator::isOperator(char c) const {
    return operatorPrecedence.find(c) != operatorPrecedence.end();
}

double Calculator::applyOperator(double a, double b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                throw std::runtime_error("Деление на ноль");
            }
            return a / b;
        default:
            throw std::runtime_error("Неизвестный оператор: " + std::string(1, op));
    }
}

bool Calculator::isDigit(char c) const {
    return c >= '0' && c <= '9';
}

bool Calculator::isSpace(char c) const {
    return c == ' ' || c == '\t';
} 
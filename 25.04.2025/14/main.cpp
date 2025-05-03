#include "calculator.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\nExpression Calculator Menu:\n"
              << "1. Calculate expression\n"
              << "2. Exit\n"
              << "Enter your choice: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Calculator calc;
    
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                std::string expression;
                std::cout << "Enter expression (e.g., '3 + 4 * 2'): ";
                std::getline(std::cin, expression);
                
                try {
                    double result = calc.calculate(expression);
                    std::cout << "Result: " << result << "\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 2:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
} 
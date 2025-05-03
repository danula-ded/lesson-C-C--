#include "password_generator.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\nPassword Generator Menu:\n"
              << "1. Generate new password\n"
              << "2. Exit\n"
              << "Enter your choice: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    PasswordGenerator generator;
    
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                int length;
                bool useLetters, useNumbers, useSpecial;
                
                std::cout << "Enter password length: ";
                std::cin >> length;
                clearInputBuffer();
                
                if (length < 4) {
                    std::cout << "Password length must be at least 4 characters.\n";
                    break;
                }
                
                std::cout << "Include letters? (1/0): ";
                std::cin >> useLetters;
                std::cout << "Include numbers? (1/0): ";
                std::cin >> useNumbers;
                std::cout << "Include special characters? (1/0): ";
                std::cin >> useSpecial;
                clearInputBuffer();
                
                std::string password = generator.generatePassword(length, useLetters, useNumbers, useSpecial);
                std::cout << "\nGenerated password: " << password << "\n";
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
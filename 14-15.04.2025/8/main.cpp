#include "Account.h"
#include "SavingsAccount.h"
#include <iostream>

int main() {
    // Create a regular account
    Account regularAccount;
    regularAccount.deposit(1000.0);
    std::cout << "Regular Account Balance: $" << regularAccount.getBalance() << std::endl;

    // Create a savings account with 5% interest rate
    SavingsAccount savingsAccount(0.05);
    savingsAccount.deposit(1000.0);
    std::cout << "Savings Account Balance: $" << savingsAccount.getBalance() << std::endl;
    std::cout << "Interest earned: $" << savingsAccount.calculateInterest() << std::endl;

    // Add more money to savings account
    savingsAccount.deposit(500.0);
    std::cout << "\nAfter additional deposit:" << std::endl;
    std::cout << "Savings Account Balance: $" << savingsAccount.getBalance() << std::endl;
    std::cout << "Interest earned: $" << savingsAccount.calculateInterest() << std::endl;

    return 0;
} 
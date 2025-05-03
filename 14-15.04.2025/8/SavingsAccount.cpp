#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double rate) : interestRate(rate) {}

double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
} 
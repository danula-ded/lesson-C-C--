#include "Account.h"

Account::Account() : balance(0.0) {}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

double Account::getBalance() const {
    return balance;
} 
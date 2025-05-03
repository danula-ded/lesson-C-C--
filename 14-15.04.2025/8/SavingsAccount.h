#pragma once
#include "Account.h"

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(double rate);
    double calculateInterest() const;
}; 
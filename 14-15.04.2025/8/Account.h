#pragma once

class Account {
private:
    double balance;

public:
    Account();
    void deposit(double amount);
    double getBalance() const;
}; 
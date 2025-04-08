#include <iostream>

class BankAccount {
private:
    double balance;
    int accountNumber;

public:
    BankAccount(int accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
    }

    void printInfo() const {
        std::cout << "Account: " << accountNumber << ", Balance: " << balance << "\n";
    }
};

int main() {
    BankAccount acc(12345, 1000.0);
    acc.deposit(500);
    acc.withdraw(200);
    acc.printInfo();
    return 0;
}

#include <iostream>
#include <stdexcept>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds");
        }
        balance -= amount;
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw std::invalid_argument("Negative deposit");
        }
        balance += amount;
    }

    void printBalance() const {
        std::cout << "Balance: " << balance << "\n";
    }
};

int main() {
    try {
        BankAccount acc(500.0);
        acc.deposit(100);
        acc.withdraw(700); // выбросит исключение
        acc.printBalance();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}

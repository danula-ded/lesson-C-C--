#include <stdio.h>

typedef struct {
    double balance;
} BankAccount;

int deposit(BankAccount* acc, double amount) {
    if (amount < 0) return -1;
    acc->balance += amount;
    return 0;
}

int withdraw(BankAccount* acc, double amount) {
    if (amount > acc->balance) return -2;
    acc->balance -= amount;
    return 0;
}

void printBalance(const BankAccount* acc) {
    printf("Balance: %.2f\n", acc->balance);
}

int main() {
    BankAccount acc = {500.0};

    if (deposit(&acc, 100) != 0) {
        printf("Error: invalid deposit\n");
    }

    int result = withdraw(&acc, 700);
    if (result == -2) {
        printf("Error: insufficient funds\n");
    }

    printBalance(&acc);
    return 0;
}

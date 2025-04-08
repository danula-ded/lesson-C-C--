#include <stdio.h>

static double balance;
static int accountNumber;

void initAccount(int accNum, double initialBalance) {
    accountNumber = accNum;
    balance = initialBalance;
}

void deposit(double amount) {
    if (amount > 0) balance += amount;
}

void withdraw(double amount) {
    if (amount > 0 && amount <= balance) balance -= amount;
}

void printInfo() {
    printf("Account: %d, Balance: %.2f\n", accountNumber, balance);
}

int main() {
    initAccount(12345, 1000.0);
    deposit(500);
    withdraw(200);
    printInfo();
    return 0;
}

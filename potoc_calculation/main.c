#include <stdio.h>
#include <locale.h>
#include "functions.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    float a, b;
    char op;

    printf("Введите выражение (например, 2 + 3): ");
    scanf("%f %c %f", &a, &op, &b);

    switch (op) {
        case '+': 
            execute(add, a, b);
            break;
        case '-': 
            execute(subtract, a, b);
            break;
        case '*': 
            execute(multiply, a, b);
            break;
        case '/': 
            execute(divide, a, b);
            break;
        case '%': 
            execute(int_divide, a, b);
            break;
        default: return 1;
    }


    return 0;
}
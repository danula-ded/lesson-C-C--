#include <stdio.h>
#include "math_functions.h"

void add(float a, float b) {
    printf("Результат: %.2f + %.2f = %.2f\n", a, b, a + b);
}

void subtract(float a, float b) {
    printf("Результат: %.2f - %.2f = %.2f\n", a, b, a - b);
}

void multiply(float a, float b) {
    printf("Результат: %.2f * %.2f = %.2f\n", a, b, a * b);
}

void divide(float a, float b) {
    if (b == 0.0) {
        printf("Ошибка: деление на ноль!\n");
        return;
    }
    printf("Результат: %.2f / %.2f = %.2f\n", a, b, a / b);
}

void int_divide(int a, int b) {
    if (b == 0) {
        printf("Ошибка: деление на ноль!\n");
        return;
    }
    printf("Результат: %d // %d = %d\n", a, b, a / b);
}

void modulus(int a, int b){
    if (b == 0.0) {
        printf("Ошибка: деление на ноль!\n");
        return;
    }
    printf("Результат: %d // %d = %d\n", a, b, a % b);
}


void execute(void (*func)(float, float), float a, float b) {
    return func(a, b);
}
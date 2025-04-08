#include <stdio.h>
#include <math.h>
#include "math_functions.h"

void add(float a, float b) {
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
}

void subtract(float a, float b) {
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
}

void multiply(float a, float b) {
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
}

void divide(float a, float b) {
    if (b == 0.0) {
        printf("Ошибка: деление на ноль!\n");
        return;
    }
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);
}

void int_divide(int a, int b) {
    if (b == 0) {
        printf("Ошибка: деление на ноль!\n");
        return;
    }
    printf("%d / %d = %d\n", a, b, a / b);
}

void modulus(int a, int b){
    if (b == 0.0) {
        printf("Ошибка: деление на ноль!\n");
        return;
    }
    printf("%d // %d = %d\n", a, b, a % b);
}

void power(float a, float b) {
    printf("%.2f ^ %.2f = %.2f\n", a, b, powf(a, b));
}

void compare(float a, float b) {
    if (a > b) {
        printf("%.2f > %.2f\n", a, b);
    } else if (a < b) {
        printf("%.2f < %.2f\n", a, b);
    } else {
        printf("%.2f == %.2f\n", a, b);
    }
}


void execute(void (*func)(float, float), float a, float b) {
    return func(a, b);
}

void execute_operations(float_operation ops[], int count, float a, float b) {
    for (int i = 0; i < count; i++) {
        ops[i](a, b);
    }
}
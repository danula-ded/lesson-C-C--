#include <stdio.h>
#include <locale.h>
#include "math_functions.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    float a, b;

    printf("Введите выражение (например, 2 3): ");
    scanf("%f %f", &a, &b);

    float_operation float_ops[] = {add, subtract, multiply, divide, compare, power};
    int float_ops_count = sizeof(float_ops) / sizeof(float_ops[0]);

    execute(add, a, b);
    execute(subtract, a, b);
    execute(multiply, a, b);
    execute(divide, a, b);
    int_divide((int)a, (int)b);
    modulus((int)a, (int)b);
    execute(power, a, b);
    execute(compare, a, b);

    printf("\nРезультаты операций:\n");
    execute_operations(float_ops, float_ops_count, a, b);

    return 0;
}
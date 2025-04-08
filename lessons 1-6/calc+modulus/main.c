#include <stdio.h>
#include <locale.h>
#include "math_functions.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    float a, b;

    printf("Введите выражение (например, 2 3): ");
    scanf("%f %f", &a, &b);

    execute(add, a, b);
    execute(subtract, a, b);
    execute(multiply, a, b);
    execute(divide, a, b);
    int_divide((int)a, (int)b);
    modulus((int)a, (int)b);

    return 0;
}
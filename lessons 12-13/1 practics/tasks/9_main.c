#include <stdio.h>

// Функция сложения
int add(int a, int b) {
    return a + b;
}

// Функция вычитания
int subtract(int a, int b) {
    return a - b;
}

int main() {
    int x, y;

    printf("Введите два числа:\n");
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    int sum = add(x, y);
    int diff = subtract(x, y);

    printf("Сумма: %d + %d = %d\n", x, y, sum);
    printf("Разность: %d - %d = %d\n", x, y, diff);

    return 0;
}

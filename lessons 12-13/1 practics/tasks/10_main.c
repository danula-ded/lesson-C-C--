#include <stdio.h>

int main() {
    int number;
    int count = 0;

    printf("Введите числа (введите 0 для завершения):\n");

    while (1) {
        scanf("%d", &number);
        if (number == 0) {
            break;
        }
        count++;
    }

    printf("Вы ввели %d чисел(а).\n", count);
    return 0;
}

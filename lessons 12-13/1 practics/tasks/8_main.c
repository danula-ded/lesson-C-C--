#include <stdio.h>

int main() {
    int numbers[5];
    int sum = 0;

    printf("Введите 5 целых чисел:\n");
    for (int i = 0; i < 5; i++) {
        printf("Число %d: ", i + 1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    printf("Сумма введенных чисел: %d\n", sum);

    return 0;
}

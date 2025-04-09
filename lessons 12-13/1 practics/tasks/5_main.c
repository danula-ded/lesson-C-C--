#include <stdio.h>
#include <stdlib.h>

int main() {
    int staticArray[10];
    int* dynamicArray = (int*) malloc(10 * sizeof(int));

    if (dynamicArray == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    // Статический массив
    printf("Размер staticArray: %zu байт\n", sizeof(staticArray));
    printf("Размер одного элемента staticArray: %zu байт\n", sizeof(staticArray[0]));

    // Динамический массив
    printf("Размер dynamicArray (указатель): %zu байт\n", sizeof(dynamicArray));
    printf("Размер области, выделенной под dynamicArray: %zu байт\n", 10 * sizeof(int));

    free(dynamicArray);
    return 0;
}

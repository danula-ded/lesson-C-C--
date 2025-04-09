#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 10;
    int *array;
    
    array = (int*)malloc(size * sizeof(int));
    
    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
    
    printf("Элементы массива:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    free(array);
    
    return 0;
}
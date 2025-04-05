#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <pthread.h>
#include "functions.h"

#define NUM_THREADS 5

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    float a, b;
    printf("Введите два числа: ");
    scanf("%f %f", &a, &b);

    pthread_t threads[NUM_THREADS];
    void* (*functions[NUM_THREADS])(void*) = {add, subtract, multiply, divide, int_divide};

    for (int i = 0; i < NUM_THREADS; i++) {
        ThreadArgs* args = malloc(sizeof(ThreadArgs));
        args->a = a;
        args->b = b;
        args->thread_num = i + 1;
        
        if (pthread_create(&threads[i], NULL, functions[i], args) != 0) {
            perror("Не удалось создать поток");
            free(args);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nИтоговое значение счетчика: %d (ожидалось: %d)\n", counter, NUM_THREADS * 1000);

    pthread_mutex_destroy(&counter_mutex);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int counter = 0;
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void* add(void* args) {
    ThreadArgs* params = (ThreadArgs*)args;
    
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    
    printf("[Поток %d] %.2f + %.2f = %.2f\n", 
           params->thread_num, params->a, params->b, params->a + params->b);
    free(args);
    return NULL;
}

void* subtract(void* args) {
    ThreadArgs* params = (ThreadArgs*)args;
    
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    
    printf("[Поток %d] %.2f - %.2f = %.2f\n", 
           params->thread_num, params->a, params->b, params->a - params->b);
    free(args);
    return NULL;
}

void* multiply(void* args) {
    ThreadArgs* params = (ThreadArgs*)args;
    
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    
    printf("[Поток %d] %.2f * %.2f = %.2f\n", 
           params->thread_num, params->a, params->b, params->a * params->b);
    free(args);
    return NULL;
}

void* divide(void* args) {
    ThreadArgs* params = (ThreadArgs*)args;
    
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    
    if (params->b == 0.0) {
        printf("[Поток %d] Ошибка: деление на ноль!\n", params->thread_num);
    } else {
        printf("[Поток %d] %.2f / %.2f = %.2f\n", 
               params->thread_num, params->a, params->b, params->a / params->b);
    }
    free(args);
    return NULL;
}

void* int_divide(void* args) {
    ThreadArgs* params = (ThreadArgs*)args;
    
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    
    if (params->b == 0.0) {
        printf("[Поток %d] Ошибка: деление на ноль!\n", params->thread_num);
    } else {
        printf("[Поток %d] %.0f // %.0f = %.0f\n", 
               params->thread_num, params->a, params->b, params->a / params->b);
    }
    free(args);
    return NULL;
}
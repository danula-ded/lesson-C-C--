#ifndef FUNCTION_H
#define FUNCTION_H

#include <pthread.h>

void* add(void* args);
void* subtract(void* args);
void* multiply(void* args);
void* divide(void* args);
void* int_divide(void* args);

typedef struct {
    float a;
    float b;
    int thread_num;
} ThreadArgs;

extern int counter;
extern pthread_mutex_t counter_mutex;

#endif
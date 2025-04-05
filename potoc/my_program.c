#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread %d started\n", thread_num);
    
    int delay = 1 + rand()%5;
    sleep(delay);
    
    printf("Thread %d finished after %d seconds\n", thread_num, delay);
    return NULL;
}

int main() {
    srand(time(NULL));
    
    pthread_t threads[5];
    int thread_args[5];
    
    for (int i = 0; i < 5; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads have finished.\n");
    return 0;
}
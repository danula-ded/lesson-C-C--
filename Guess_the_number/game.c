#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

static int secret_number;
static int attempts; 

void init_game() {
    srand(time(0));  
    secret_number = rand() % 100 + 1;
    attempts = 0;
}

int get_user_guess() {
    int guess;
    printf("Введите вашу догадку (1-100): ");
    scanf("%d", &guess);
    attempts++;
    return guess;
}

int check_guess(int guess) {
    if (guess < secret_number) {
        printf("Больше!\n");
        return 1;
    } else if (guess > secret_number) {
        printf("Меньше!\n");
        return 1;
    } else {
        return 0;
    }
}

int get_attempts() {
    return attempts;
}
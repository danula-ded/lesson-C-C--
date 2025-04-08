#include <stdio.h>
#include <locale.h>
#include "game.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    printf("Добро пожаловать в игру 'Угадай число'!\n");
    printf("Я загадал число от 1 до 100. Попробуйте угадать!\n\n");
    
    init_game();

    int guess;
    do {
        guess = get_user_guess();
    } while (check_guess(guess)==1);
    
    printf("\nПоздравляю! Вы угадали число за %d попыток!\n", get_attempts());
    
    return 0;
}
#include "functions.h"
#include <stdio.h>

#define MAX_LEN 100

int main() {
    char surname[MAX_LEN], name[MAX_LEN], patronymic[MAX_LEN];
    
    printf("Введите ФИО через пробелы: ");
    scanf("%s %s %s", surname, name, patronymic);
    
    print_formatted_name(surname, name, patronymic);
    return 0;
}
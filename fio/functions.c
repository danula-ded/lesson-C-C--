#include "functions.h"
#include <stdio.h>

void print_formatted_name(const char* surname, 
                         const char* name, 
                         const char* patronymic) {
    printf("\n=== Ваше ФИО ===\n"
           "Фамилия: \t%s\n"
           "Имя: \t\t%s\n"
           "Отчество: \t%s\n"
           "=================\n", 
           surname, name, patronymic);
}
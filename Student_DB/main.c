#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "database.h"

void print_menu() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    printf("\n=== Меню базы данных студентов ===\n");
    printf("1. Добавить студента\n");
    printf("2. Удалить студента\n");
    printf("3. Показать всех студентов\n");
    printf("4. Сохранить в файл\n");
    printf("5. Загрузить из файла\n");
    printf("0. Выход\n");
    printf("Выберите действие: ");
}

int main() {
    init_database();

    int choice;
    char name[MAX_NAME_LENGTH];
    int age, id;
    float gpa;
    char filename[100];

    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // Очистка буфера ввода

        switch (choice) {
            case 1:
                printf("Введите имя студента: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Удаление \n
                
                printf("Введите возраст: ");
                scanf("%d", &age);
                
                printf("Введите средний балл (GPA): ");
                scanf("%f", &gpa);
                
                add_student(name, age, gpa);
                break;
                
            case 2:
                printf("Введите ID студента для удаления: ");
                scanf("%d", &id);
                delete_student(id);
                break;
                
            case 3:
                display_students();
                break;
                
            case 4:
                printf("Введите имя файла для сохранения: ");
                scanf("%99s", filename);
                save_to_file(filename);
                break;
                
            case 5:
                printf("Введите имя файла для загрузки: ");
                scanf("%99s", filename);
                load_from_file(filename);
                break;
                
            case 0:
                printf("Выход из программы...\n");
                break;
                
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    cleanup_database();
    return 0;
}
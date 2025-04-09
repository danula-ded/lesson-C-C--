#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"
#include "file_utils.h"

int main() {
    int choice;
    char str1[100], str2[100];
    char filename[100], content[200];

    while (1) {
        printf("\nМеню:\n");
        printf("1. Подсчитать длину строки\n");
        printf("2. Конкатенировать строки\n");
        printf("3. Записать в файл\n");
        printf("4. Прочитать из файла\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Введите строку: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Длина строки: %d\n", string_length(str1));
                break;
            case 2:
                printf("Введите первую строку: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Введите вторую строку: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                string_concat(str1, str2);
                printf("Результат: %s\n", str1);
                break;
            case 3:
                printf("Введите имя файла: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';
                printf("Введите содержимое: ");
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = '\0';
                write_to_file(filename, content);
                break;
            case 4:
                printf("Введите имя файла: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';
                read_from_file(filename);
                break;
            case 0:
                exit(0);
            default:
                printf("Неверный выбор!\n");
        }
    }

    return 0;
}

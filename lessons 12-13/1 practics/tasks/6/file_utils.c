#include <stdio.h>
#include "file_utils.h"

// f;iodshfouh
void write_to_file(const char* filename, const char* content) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        printf("Ошибка при открытии файла для записи.\n");
        return;
    }
    fprintf(f, "%s", content);
    fclose(f);
}

void read_from_file(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Ошибка при открытии файла для чтения.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }
    fclose(f);
}

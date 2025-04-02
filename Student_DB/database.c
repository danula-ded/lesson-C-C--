#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

static Student *students = NULL;
static int student_count = 0;
static int database_initialized = 0;

void init_database() {
    if (!database_initialized) {
        students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
        if (!students) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            exit(EXIT_FAILURE);
        }
        database_initialized = 1;
    }
}

void add_student(const char *name, int age, float gpa) {
    if (student_count >= MAX_STUDENTS) {
        printf("База данных заполнена!\n");
        return;
    }

    Student *s = &students[student_count];
    s->id = student_count + 1;
    strncpy(s->name, name, MAX_NAME_LENGTH - 1);
    s->name[MAX_NAME_LENGTH - 1] = '\0';
    s->age = age;
    s->gpa = gpa;

    student_count++;
    printf("Студент добавлен (ID: %d)\n", s->id);
}

void delete_student(int id) {
    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            found = 1;
            // Сдвигаем оставшихся студентов
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Студент с ID %d удален\n", id);
            break;
        }
    }
    if (!found) {
        printf("Студент с ID %d не найден\n", id);
    }
}

void display_students() {
    printf("\n=== Список студентов ===\n");
    printf("ID\tИмя\t\tВозраст\tGPA\n");
    printf("--------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", 
                students[i].id, 
                students[i].name, 
                students[i].age, 
                students[i].gpa);
    }
    printf("Всего студентов: %d\n", student_count);
}

void save_to_file(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    fwrite(&student_count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), student_count, file);

    fclose(file);
    printf("Данные сохранены в файл '%s'\n", filename);
}

void load_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return;
    }

    int count;
    fread(&count, sizeof(int), 1, file);

    if (count > MAX_STUDENTS) {
        printf("Файл содержит слишком много записей\n");
        fclose(file);
        return;
    }

    student_count = 0;
    fread(students, sizeof(Student), count, file);
    student_count = count;

    fclose(file);
    printf("Данные загружены из файла '%s'\n", filename);
}

void cleanup_database() {
    if (students) {
        free(students);
        students = NULL;
    }
    student_count = 0;
    database_initialized = 0;
}
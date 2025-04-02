#ifndef DATABASE_H
#define DATABASE_H

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
} Student;

void init_database();

void add_student(const char *name, int age, float gpa);

void delete_student(int id);

void display_students();

void save_to_file(const char *filename);

void load_from_file(const char *filename);

void cleanup_database();

#endif
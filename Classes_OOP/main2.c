#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    void (*sayHello)(void*);
    void (*displayInfo)(void*);
    const char* (*getName)(void*);
    void (*setName)(void*, const char*);
    int (*getAge)(void*);
    void (*setAge)(void*, int);
} Person;

typedef struct {
    Person base;
    char university[50];
    void (*study)(void*);
    const char* (*getUniversity)(void*);
    void (*setUniversity)(void*, const char*);
} Student;

const char* person_getName(void* p) {
    Person* person = (Person*)p;
    return person->name;
}

void person_setName(void* p, const char* name) {
    Person* person = (Person*)p;
    strncpy(person->name, name, sizeof(person->name) - 1);
    person->name[sizeof(person->name) - 1] = '\0';
}

int person_getAge(void* p) {
    Person* person = (Person*)p;
    return person->age;
}

void person_setAge(void* p, int age) {
    Person* person = (Person*)p;
    if (age > 0 && age < 150) {
        person->age = age;
    }
}

void person_sayHello(void* p) {
    Person* person = (Person*)p;
    printf("Привет, меня зовут %s!\n", person->name);
}

void person_displayInfo(void* p) {
    Person* person = (Person*)p;
    printf("Имя: %s, Возраст: %d\n", person->name, person->age);
}

const char* student_getUniversity(void* s) {
    Student* student = (Student*)s;
    return student->university;
}

void student_setUniversity(void* s, const char* university) {
    Student* student = (Student*)s;
    strncpy(student->university, university, sizeof(student->university) - 1);
    student->university[sizeof(student->university) - 1] = '\0';
}

void student_study(void* s) {
    Student* student = (Student*)s;
    printf("%s учится в %s\n", student->base.getName(&student->base), student->university);
}

Student* createStudent(const char* name, int age, const char* university) {
    Student* student = (Student*)malloc(sizeof(Student));
    
    student->base.sayHello = person_sayHello;
    student->base.displayInfo = person_displayInfo;
    student->base.getName = person_getName;
    student->base.setName = person_setName;
    student->base.getAge = person_getAge;
    student->base.setAge = person_setAge;
    
    student->study = student_study;
    student->getUniversity = student_getUniversity;
    student->setUniversity = student_setUniversity;
    
    student->base.setName(&student->base, name);
    student->base.setAge(&student->base, age);
    student->setUniversity(student, university);
    
    return student;
}

void greetPerson(Person* p) {
    p->sayHello(p);
}

int main() {
    Student* student = createStudent("Иван", 20, "КМПО");
    
    printf("Информация о студенте:\n");
    student->base.displayInfo(&(student->base));
    student->study(student);
    
    printf("\nДемонстрация полиморфизма:\n");
    greetPerson((Person*)student);
    
    printf("\nДемонстрация геттеров и сеттеров:\n");
    printf("Текущее имя: %s\n", student->base.getName(&student->base));
    printf("Текущий возраст: %d\n", student->base.getAge(&student->base));
    printf("Текущий университет: %s\n", student->getUniversity(student));
    
    student->base.setName(&student->base, "Петр");
    student->base.setAge(&student->base, 21);
    student->setUniversity(student, "Сириус");
    
    printf("\nПосле изменения:\n");
    student->base.displayInfo(&(student->base));
    student->study(student);
    
    free(student);
    return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void initPerson(Person *p, const char *name, int age) {
    strncpy(p->name, name, sizeof(p->name));
    p->age = age;
}

void printPerson(const Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int main() {
    Person p;
    initPerson(&p, "Alice", 30);
    printPerson(&p);
    return 0;
}

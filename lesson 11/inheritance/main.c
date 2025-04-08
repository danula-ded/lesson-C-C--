#include <stdio.h>
#include <stdlib.h>

typedef struct Animal {
    void (*speak)(struct Animal*);
} Animal;

typedef struct Dog {
    Animal base;
} Dog;

typedef struct Cat {
    Animal base;
} Cat;

void dogSpeak(Animal* a) {
    printf("Woof!\n");
}

void catSpeak(Animal* a) {
    printf("Meow!\n");
}

void initDog(Dog* d) {
    d->base.speak = dogSpeak;
}

void initCat(Cat* c) {
    c->base.speak = catSpeak;
}

int main() {
    Dog d;
    Cat c;

    initDog(&d);
    initCat(&c);

    Animal* a1 = (Animal*)&d;
    Animal* a2 = (Animal*)&c;

    a1->speak(a1);
    a2->speak(a2);

    return 0;
}

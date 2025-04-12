#include "animal.h"
#include "dog.h"
#include "cat.h"
#include <memory>

int main() {
    Animal animal("Generic", 5);
    Dog dog("Rex", 3, "Labrador");
    Cat cat("Whiskers", 2, "black");

    animal.speak();
    dog.speak();
    cat.speak();

    return 0;
}
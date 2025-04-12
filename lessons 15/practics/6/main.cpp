#include "library.h"
#include <iostream>

int main() {
    Library library;

    library.addBook("Война и мир", 3);
    library.addBook("Мастер и Маргарита", 7);
    library.addBook("Преступление и наказание", 5);

    library.addReader("Иван Иванов");
    library.addReader("Петр Петров");

    library.borrowBook("Иван Иванов", "Война и мир");
    library.borrowBook("Иван Иванов", "Мастер и Маргарита");
    library.borrowBook("Петр Петров", "Преступление и наказание");

    library.displayStatus();

    std::cout << "\nAfter returning some books:" << std::endl;
    library.returnBook("Иван Иванов", "Война и мир");
    library.returnBook("Петр Петров", "Преступление и наказание");

    library.displayStatus();

    return 0;
} 
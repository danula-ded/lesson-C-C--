#include <iostream>
#include "book.h"
#include "library.h"

int main() {
    Library lib;

    lib.addBook(Book("1984", "George Orwell", 9.99));
    lib.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 12.50));

    std::cout << "Все книги в библиотеке:" << std::endl;
    lib.displayAllBooks();

    Book* foundBook = lib.findBook("1984");
    if (foundBook) {
        std::cout << "Найдена книга: " << foundBook->getTitle() << std::endl;
    } else {
        std::cout << "Книги нема(((" << std::endl;
    }
    
    lib.removeBook("The Great Gatsby");
    std::cout << "\nПосле удаления:" << std::endl;
    Book* foundBook2 = lib.findBook("The Great Gatsby");
    if (foundBook2) {
        std::cout << "Найдена книга: " << foundBook->getTitle() << std::endl;
    } else {
        std::cout << "Книги нема(((" << std::endl;
    }
    
    lib.displayAllBooks();
    
    return 0;
}
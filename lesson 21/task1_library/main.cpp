#include "library.h"
#include <iostream>

int main() {
    Library library;

    // Adding some books
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    library.addBook(Book("1984", "George Orwell", 1949));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));

    // Display all books
    std::cout << "Initial library contents:\n";
    library.displayAllBooks();

    // Remove a book
    std::cout << "\nRemoving '1984'...\n";
    library.removeBook("1984");

    // Display books after removal
    std::cout << "\nLibrary contents after removal:\n";
    library.displayAllBooks();

    return 0;
} 
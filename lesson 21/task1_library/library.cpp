#include "library.h"
#include <algorithm>
#include <iostream>

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(const std::string& title) {
    books.erase(
        std::remove_if(books.begin(), books.end(),
            [&title](const Book& book) { return book.getTitle() == title; }),
        books.end()
    );
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "Library is empty.\n";
        return;
    }

    std::cout << "Library Contents:\n";
    for (const auto& book : books) {
        book.display();
    }
} 
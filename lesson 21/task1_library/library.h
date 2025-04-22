#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void removeBook(const std::string& title);
    void displayAllBooks() const;
};

#endif // LIBRARY_H 
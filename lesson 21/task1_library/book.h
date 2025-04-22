#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book(const std::string& title, const std::string& author, int year);
    void display() const;
    const std::string& getTitle() const;
};

#endif // BOOK_H 
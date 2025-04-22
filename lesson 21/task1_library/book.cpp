#include "book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {}

void Book::display() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Year: " << year << "\n"
              << "------------------------\n";
}

const std::string& Book::getTitle() const {
    return title;
} 
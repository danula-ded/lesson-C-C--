#include "book.h"

Book::Book() : title(""), author(""), price(0.0) {}

Book::Book(const std::string& title, const std::string& author, double price)
    : title(title), author(author), price(price) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
double Book::getPrice() const { return price; }

void Book::setTitle(const std::string& title) { this->title = title; }
void Book::setAuthor(const std::string& author) { this->author = author; }
void Book::setPrice(double price) { this->price = price; }
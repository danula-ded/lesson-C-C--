#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    Book();
    Book(const std::string& title, const std::string& author, double price);
    std::string getTitle() const;
    std::string getAuthor() const;
    double getPrice() const;
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setPrice(double price);
};

#endif
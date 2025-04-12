#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include <map>

class Book {
private:
    std::string title;
    int totalCopies;
    int availableCopies;

public:
    Book() = delete;
    Book(const std::string& title, int copies);
    const std::string& getTitle() const;
    int getAvailableCopies() const;
    bool borrow();
    void returnBook();
};

class Reader {
private:
    std::string name;
    std::vector<std::string> borrowedBooks;

public:
    Reader() = delete;
    Reader(const std::string& name);
    const std::string& getName() const;
    void borrowBook(const std::string& title);
    void returnBook(const std::string& title);
    const std::vector<std::string>& getBorrowedBooks() const;
};

class Library {
private:
    std::map<std::string, Book> books;
    std::map<std::string, Reader> readers;

public:
    void addBook(const std::string& title, int copies);
    void addReader(const std::string& name);
    bool borrowBook(const std::string& readerName, const std::string& bookTitle);
    bool returnBook(const std::string& readerName, const std::string& bookTitle);
    void displayStatus() const;
};

#endif 
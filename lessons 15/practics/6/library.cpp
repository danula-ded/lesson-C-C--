#include "library.h"
#include <iostream>
#include <algorithm> // Добавляем этот заголовочный файл

Book::Book(const std::string& title, int copies)
    : title(title), totalCopies(copies), availableCopies(copies) {}

const std::string& Book::getTitle() const {
    return title;
}

int Book::getAvailableCopies() const {
    return availableCopies;
}

bool Book::borrow() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

void Book::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
    }
}

Reader::Reader(const std::string& name) : name(name) {}

const std::string& Reader::getName() const {
    return name;
}

void Reader::borrowBook(const std::string& title) {
    borrowedBooks.push_back(title);
}

void Reader::returnBook(const std::string& title) {
    borrowedBooks.erase(
        std::remove(borrowedBooks.begin(), borrowedBooks.end(), title),
        borrowedBooks.end()
    );
}

const std::vector<std::string>& Reader::getBorrowedBooks() const {
    return borrowedBooks;
}

void Library::addBook(const std::string& title, int copies) {
    books.emplace(std::piecewise_construct,
                 std::forward_as_tuple(title),
                 std::forward_as_tuple(title, copies));
}

void Library::addReader(const std::string& name) {
    readers.emplace(std::piecewise_construct,
                   std::forward_as_tuple(name),
                   std::forward_as_tuple(name));
}

bool Library::borrowBook(const std::string& readerName, const std::string& bookTitle) {
    auto readerIt = readers.find(readerName);
    auto bookIt = books.find(bookTitle);

    if (readerIt == readers.end() || bookIt == books.end()) {
        return false;
    }

    if (bookIt->second.borrow()) {
        readerIt->second.borrowBook(bookTitle);
        return true;
    }
    return false;
}

bool Library::returnBook(const std::string& readerName, const std::string& bookTitle) {
    auto readerIt = readers.find(readerName);
    auto bookIt = books.find(bookTitle);

    if (readerIt == readers.end() || bookIt == books.end()) {
        return false;
    }

    bookIt->second.returnBook();
    readerIt->second.returnBook(bookTitle);
    return true;
}

void Library::displayStatus() const {
    std::cout << "Library Status:" << std::endl;
    std::cout << "Books:" << std::endl;
    for (const auto& [title, book] : books) {
        std::cout << "- " << title << ": " 
                  << book.getAvailableCopies() << "/" 
                  << book.getAvailableCopies() + (book.getAvailableCopies() - book.getAvailableCopies()) 
                  << " available" << std::endl;
    }

    std::cout << "\nReaders:" << std::endl;
    for (const auto& [name, reader] : readers) {
        std::cout << "- " << name << " has borrowed:" << std::endl;
        for (const auto& book : reader.getBorrowedBooks()) {
            std::cout << "  * " << book << std::endl;
        }
    }
}
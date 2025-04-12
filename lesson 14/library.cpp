#include "library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(const std::string& title) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            return;
        }
    }
    std::cout << "Книга с названием '" << title << "' не найдена." << std::endl;
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "Библиотека пуста." << std::endl;
        return;
    }
    for (const auto& book : books) {
        std::cout << "Название: " << book.getTitle() 
                  << ", Автор: " << book.getAuthor() 
                  << ", Цена: $" << book.getPrice() << std::endl;
    }
}

Book* Library::findBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            return &book;
        }
    }
    return nullptr;
}
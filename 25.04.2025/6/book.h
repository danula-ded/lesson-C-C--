#pragma once
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, int year);
    
    // Геттеры
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }
    
    // Для вывода информации о книге
    std::string toString() const;
    
private:
    std::string title;
    std::string author;
    int year;
}; 
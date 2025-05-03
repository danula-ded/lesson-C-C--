#include "book.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<Book> books;
    
    // Add books for demonstration
    books.emplace_back("War and Peace", "Tolstoy", 1869);
    books.emplace_back("Crime and Punishment", "Dostoevsky", 1866);
    books.emplace_back("Eugene Onegin", "Pushkin", 1833);
    books.emplace_back("Dead Souls", "Gogol", 1842);
    books.emplace_back("Anna Karenina", "Tolstoy", 1877);
    
    // Sort by author and year
    std::sort(books.begin(), books.end(),
              [](const Book& a, const Book& b) {
                  if (a.getAuthor() != b.getAuthor()) {
                      return a.getAuthor() < b.getAuthor();
                  }
                  return a.getYear() < b.getYear();
              });
    
    // Print header
    std::cout << std::string(56, '-') << "\n";
    std::cout << std::setw(30) << std::left << "Title"
              << std::setw(20) << std::left << "Author"
              << std::setw(6) << std::right << "Year" << "\n";
    std::cout << std::string(56, '-') << "\n";
    
    // Print sorted list
    for (const auto& book : books) {
        std::cout << book.toString() << "\n";
    }
    
    return 0;
} 
#include "book.h"
#include <sstream>
#include <iomanip>

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {}

std::string Book::toString() const {
    std::ostringstream oss;
    oss << std::setw(30) << std::left << title
        << std::setw(20) << std::left << author
        << std::setw(6) << std::right << year;
    return oss.str();
} 
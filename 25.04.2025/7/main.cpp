#include "factorial_cache.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    FactorialCache cache;
    
    std::cout << "Factorial Calculator with Caching\n";
    std::cout << "Enter a number to calculate its factorial (negative number to exit)\n\n";
    
    while (true) {
        int n;
        std::cout << "Enter number: ";
        std::cin >> n;
        
        if (n < 0) {
            break;
        }
        
        try {
            unsigned long long result = cache.getFactorial(n);
            std::cout << n << "! = " << result << "\n";
            std::cout << "Cache statistics:\n";
            std::cout << "Hits: " << cache.getCacheHits() << "\n";
            std::cout << "Misses: " << cache.getCacheMisses() << "\n\n";
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n\n";
        }
        
        clearInputBuffer();
    }
    
    return 0;
} 
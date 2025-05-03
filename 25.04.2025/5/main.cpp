#include "text_analyzer.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

int main() {
    TextAnalyzer analyzer;
    std::string filename;
    
    std::cout << "Enter filename for analysis (press Enter to use test.txt): ";
    std::getline(std::cin, filename);
    
    // Use test.txt if no filename provided
    if (filename.empty()) {
        filename = "test.txt";
    }
    
    if (!analyzer.loadFromFile(filename)) {
        std::cout << "Error opening file: " << filename << "\n";
        return 1;
    }
    
    analyzer.analyzeFrequency();
    auto results = analyzer.getFrequencyResults();
    
    std::cout << "\nLetter frequency in file '" << filename << "' (in descending order):\n";
    std::cout << std::setw(10) << "Letter" << std::setw(10) << "Count" << "\n";
    std::cout << std::string(20, '-') << "\n";
    
    for (const auto& [letter, count] : results) {
        std::cout << std::setw(10) << letter << std::setw(10) << count << "\n";
    }
    
    return 0;
} 
#include "text_analyzer.h"
#include <fstream>
#include <algorithm>
#include <cctype>

bool TextAnalyzer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    text.clear();
    std::string line;
    while (std::getline(file, line)) {
        text += line + "\n";
    }
    
    return true;
}

void TextAnalyzer::analyzeFrequency() {
    frequency.clear();
    
    for (char c : text) {
        if (std::isalpha(c)) {
            frequency[std::tolower(c)]++;
        }
    }
}

std::vector<std::pair<char, int>> TextAnalyzer::getFrequencyResults() const {
    std::vector<std::pair<char, int>> results(frequency.begin(), frequency.end());
    
    // Sort by frequency in descending order
    std::sort(results.begin(), results.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });
    
    return results;
} 
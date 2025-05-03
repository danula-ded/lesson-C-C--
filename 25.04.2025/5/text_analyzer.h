#pragma once
#include <map>
#include <string>
#include <vector>

class TextAnalyzer {
public:
    // Load text from file
    bool loadFromFile(const std::string& filename);
    
    // Analyze letter frequency
    void analyzeFrequency();
    
    // Get analysis results
    std::vector<std::pair<char, int>> getFrequencyResults() const;
    
private:
    std::string text;
    std::map<char, int> frequency;
}; 
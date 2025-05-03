#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>

// Function to get the last character of a word
char getLastChar(const std::string& word) {
    if (word.empty()) return '\0';
    return std::tolower(word[word.length() - 1]);
}

// Function to get the first character of a word
char getFirstChar(const std::string& word) {
    if (word.empty()) return '\0';
    return std::tolower(word[0]);
}

int main() {
    std::set<std::string> words;
    std::string word;
    char lastChar = '\0';
    
    std::cout << "Enter words (each new word must start with the last letter of the previous word).\n";
    std::cout << "Enter empty line to exit.\n\n";
    
    while (true) {
        std::cout << "Enter word: ";
        std::getline(std::cin, word);
        
        // Check for empty line to exit
        if (word.empty()) {
            break;
        }
        
        // Check for word repetition
        if (words.find(word) != words.end()) {
            std::cout << "This word has already been used!\n";
            continue;
        }
        
        // If this is the first word
        if (words.empty()) {
            words.insert(word);
            lastChar = getLastChar(word);
            std::cout << "Next word must start with letter: " << lastChar << "\n";
            continue;
        }
        
        // Check the rule
        if (getFirstChar(word) != lastChar) {
            std::cout << "Word must start with letter: " << lastChar << "\n";
            std::cout << "Game over!\n";
            break;
        }
        
        // Add word to set
        words.insert(word);
        lastChar = getLastChar(word);
        std::cout << "Next word must start with letter: " << lastChar << "\n";
    }
    
    // Print all used words
    std::cout << "\nUsed words:\n";
    for (const auto& w : words) {
        std::cout << w << "\n";
    }
    
    return 0;
} 
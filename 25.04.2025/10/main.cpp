#include "trie.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <string>

void printMenu() {
    std::cout << "\nDictionary Autocomplete Menu:\n"
              << "1. Add word to dictionary\n"
              << "2. Search words by prefix\n"
              << "3. Check if word exists\n"
              << "4. Load words from file\n"
              << "5. Exit\n"
              << "Enter your choice: ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Trie dictionary;
    
    // Add some example words
    dictionary.insert("apple");
    dictionary.insert("application");
    dictionary.insert("banana");
    dictionary.insert("ball");
    dictionary.insert("cat");
    dictionary.insert("car");
    
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                std::string word;
                std::cout << "Enter word to add: ";
                std::getline(std::cin, word);
                
                if (!word.empty()) {
                    dictionary.insert(word);
                    std::cout << "Word added successfully.\n";
                } else {
                    std::cout << "Word cannot be empty.\n";
                }
                break;
            }
            case 2: {
                std::string prefix;
                std::cout << "Enter prefix to search: ";
                std::getline(std::cin, prefix);
                
                auto words = dictionary.findWordsWithPrefix(prefix);
                if (words.empty()) {
                    std::cout << "No words found with prefix '" << prefix << "'\n";
                } else {
                    std::cout << "Found " << words.size() << " words:\n";
                    for (const auto& word : words) {
                        std::cout << "- " << word << "\n";
                    }
                }
                break;
            }
            case 3: {
                std::string word;
                std::cout << "Enter word to check: ";
                std::getline(std::cin, word);
                
                if (dictionary.contains(word)) {
                    std::cout << "Word '" << word << "' exists in dictionary.\n";
                } else {
                    std::cout << "Word '" << word << "' not found in dictionary.\n";
                }
                break;
            }
            case 4: {
                std::string filename;
                std::cout << "Enter filename to load words from: ";
                std::getline(std::cin, filename);
                
                std::ifstream file(filename);
                if (!file.is_open()) {
                    std::cout << "Failed to open file '" << filename << "'\n";
                    break;
                }
                
                std::string word;
                int count = 0;
                while (std::getline(file, word)) {
                    if (!word.empty()) {
                        dictionary.insert(word);
                        count++;
                    }
                }
                
                std::cout << "Loaded " << count << " words from file.\n";
                break;
            }
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
} 
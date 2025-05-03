#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>
#include <codecvt>

int main() {
    setlocale(LC_ALL, "Russian");
    std::locale::global(std::locale("ru_RU.UTF-8"));
    
    std::vector<std::string> strings;
    std::string input;
    
    std::cout << "Enter strings (one per line). Press Enter twice to finish:" << std::endl;
    
    while (true) {
        std::getline(std::cin, input);
        if (input.empty()) {
            break;
        }
        strings.push_back(input);
    }
    
    if (strings.empty()) {
        std::cout << "No strings were entered!" << std::endl;
        return 0;
    }
    
    // Сортировка по длине строки
    std::sort(strings.begin(), strings.end(), 
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
    
    std::cout << "\nSorted strings by length:" << std::endl;
    for (const auto& str : strings) {
        std::cout << "Length " << str.length() << ": " << str << std::endl;
    }
    
    return 0;
} 
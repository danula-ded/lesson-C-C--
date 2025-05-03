#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::locale::global(std::locale("ru_RU.UTF-8"));
    
    std::vector<int> numbers;
    std::string line;
    
    std::cout << "Enter numbers (separated by spaces). Enter 0 to finish:" << std::endl;
    
    while (true) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int num;
        
        while (iss >> num) {
            if (num == 0) {
                goto end_input; // Выход из ввода при вводе 0
            }
            numbers.push_back(num);
        }
    }
    
end_input:
    if (numbers.empty()) {
        std::cout << "No numbers were entered!" << std::endl;
        return 0;
    }
    
    // Создание множества для хранения уникальных элементов
    std::set<int> uniqueNumbers(numbers.begin(), numbers.end());
    
    std::cout << "\nOriginal numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Unique numbers in ascending order: ";
    for (const auto& num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
} 
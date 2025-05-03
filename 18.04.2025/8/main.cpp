#include "errors.h"
#include <iostream>
#include <memory>

int main() {
    ErrorManager manager;
    
    // Add different errors to the manager
    manager.addError(std::make_unique<FileError>("Не удалось открыть файл", "config.txt"));
    manager.addError(std::make_unique<NetworkError>("Соединение прервано", "https://example.com"));
    manager.addError(std::make_unique<FileError>("Ошибка записи", "data.dat"));
    manager.addError(std::make_unique<NetworkError>("Таймаут", "https://api.example.com"));
    manager.addError(std::make_unique<FileError>("Файл не найден", "settings.json"));
    
    // Log all errors
    std::cout << "Logging all errors:" << std::endl;
    manager.logAllErrors();
    
    return 0;
} 
#ifndef ERRORS_H
#define ERRORS_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Error {
protected:
    std::string message;
public:
    Error(const std::string& msg) : message(msg) {}
    virtual ~Error() {}
    virtual void logError() = 0;
    std::string getMessage() const { return message; }
};

class FileError : public Error {
private:
    std::string filename;
public:
    FileError(const std::string& msg, const std::string& file) 
        : Error(msg), filename(file) {}
    void logError() override {
        std::cout << "Ошибка файла: " << message << " (Файл: " << filename << ")" << std::endl;
    }
};

class NetworkError : public Error {
private:
    std::string url;
public:
    NetworkError(const std::string& msg, const std::string& url) 
        : Error(msg), url(url) {}
    void logError() override {
        std::cout << "Сетевая ошибка: " << message << " (URL: " << url << ")" << std::endl;
    }
};

class ErrorManager {
private:
    std::vector<std::unique_ptr<Error>> errors;
public:
    void addError(std::unique_ptr<Error> error) {
        errors.push_back(std::move(error));
    }
    
    void logAllErrors() {
        for (const auto& error : errors) {
            error->logError();
        }
    }
};

#endif // ERRORS_H 
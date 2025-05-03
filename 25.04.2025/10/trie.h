#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

class Trie {
public:
    Trie();
    
    // Добавление слова в словарь
    void insert(const std::string& word);
    
    // Поиск всех слов с заданным префиксом
    std::vector<std::string> findWordsWithPrefix(const std::string& prefix) const;
    
    // Проверка наличия слова
    bool contains(const std::string& word) const;
    
private:
    struct Node {
        std::unordered_map<char, std::unique_ptr<Node>> children;
        bool isEndOfWord = false;
    };
    
    std::unique_ptr<Node> root;
    
    // Вспомогательные функции
    void collectWords(Node* node, const std::string& prefix, std::vector<std::string>& words) const;
    Node* findNode(const std::string& prefix) const;
}; 
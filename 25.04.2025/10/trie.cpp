#include "trie.h"

Trie::Trie() : root(std::make_unique<Node>()) {}

void Trie::insert(const std::string& word) {
    Node* current = root.get();
    
    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = std::make_unique<Node>();
        }
        current = current->children[c].get();
    }
    
    current->isEndOfWord = true;
}

bool Trie::contains(const std::string& word) const {
    Node* node = findNode(word);
    return node != nullptr && node->isEndOfWord;
}

std::vector<std::string> Trie::findWordsWithPrefix(const std::string& prefix) const {
    std::vector<std::string> words;
    Node* node = findNode(prefix);
    
    if (node != nullptr) {
        collectWords(node, prefix, words);
    }
    
    return words;
}

Trie::Node* Trie::findNode(const std::string& prefix) const {
    Node* current = root.get();
    
    for (char c : prefix) {
        auto it = current->children.find(c);
        if (it == current->children.end()) {
            return nullptr;
        }
        current = it->second.get();
    }
    
    return current;
}

void Trie::collectWords(Node* node, const std::string& prefix, std::vector<std::string>& words) const {
    if (node->isEndOfWord) {
        words.push_back(prefix);
    }
    
    for (const auto& [c, child] : node->children) {
        collectWords(child.get(), prefix + c, words);
    }
} 
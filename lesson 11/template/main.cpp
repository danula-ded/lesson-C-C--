#include <iostream>
#include <stdexcept>

template <typename T>
class Container {
private:
    T* elements;
    size_t capacity;
    size_t size;

public:
    Container() : elements(nullptr), capacity(0), size(0) {}
    
    ~Container() {
        delete[] elements;
    }

    void add(const T& element) {
        if (size >= capacity) {
            capacity = capacity == 0 ? 1 : capacity * 2;
            T* newElements = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
        }
        elements[size++] = element;
    }

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            elements[i] = elements[i + 1];
        }
        size--;
    }

    T& get(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    // Пример с int
    Container<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);
    
    std::cout << "Int container:\n";
    for (size_t i = 0; i < intContainer.getSize(); ++i) {
        std::cout << intContainer.get(i) << " ";
    }
    std::cout << "\n";
    
    // Пример с string
    Container<std::string> strContainer;
    strContainer.add("Hello");
    strContainer.add("World");
    
    std::cout << "String container:\n";
    for (size_t i = 0; i < strContainer.getSize(); ++i) {
        std::cout << strContainer.get(i) << " ";
    }
    std::cout << "\n";
    
    return 0;
}
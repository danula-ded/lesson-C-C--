#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void printInfo() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << std::endl;
    }
};

int main() {
    Person p("Alice", 30);
    p.printInfo();
    return 0;
}

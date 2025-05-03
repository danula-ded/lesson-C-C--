#include "Manager.h"
#include "Intern.h"
#include <iostream>

int main() {
    Manager manager;
    Intern intern;
    
    std::cout << "Менеджер: ";
    manager.work();
    
    std::cout << "Стажер: ";
    intern.work();
    
    return 0;
} 
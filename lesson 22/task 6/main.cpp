#include "employee.h"

int main() {
    Manager manager;
    Intern intern;

    std::cout << "Manager: ";
    manager.work();

    std::cout << "Intern: ";
    intern.work();

    // Demonstrate polymorphism
    Employee* employees[] = {&manager, &intern};
    std::cout << "\nThrough base class pointers:" << std::endl;
    for (const auto& emp : employees) {
        emp->work();
    }

    return 0;
} 
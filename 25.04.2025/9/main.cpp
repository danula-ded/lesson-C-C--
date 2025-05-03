#include "task_manager.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\nTask Management System Menu:\n"
              << "1. Add new task\n"
              << "2. Get next task\n"
              << "3. Show all tasks\n"
              << "4. Exit\n"
              << "Enter your choice: ";
}

int main() {
    TaskManager taskManager;
    
    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }
        
        switch (choice) {
            case 1: {
                std::string description;
                int priority;
                
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                
                std::cout << "Enter task priority (1-10): ";
                std::cin >> priority;
                
                if (priority < 1 || priority > 10) {
                    std::cout << "Priority must be between 1 and 10.\n";
                    break;
                }
                
                taskManager.addTask(description, priority);
                std::cout << "Task added successfully.\n";
                break;
            }
            case 2: {
                if (!taskManager.hasTasks()) {
                    std::cout << "No tasks available.\n";
                    break;
                }
                
                Task nextTask = taskManager.getNextTask();
                std::cout << "Next task: " << nextTask.toString() << "\n";
                break;
            }
            case 3: {
                auto allTasks = taskManager.getAllTasks();
                if (allTasks.empty()) {
                    std::cout << "No tasks available.\n";
                    break;
                }
                
                std::cout << "\nAll tasks (in priority order):\n";
                for (const auto& task : allTasks) {
                    std::cout << task.toString() << "\n";
                }
                break;
            }
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
} 
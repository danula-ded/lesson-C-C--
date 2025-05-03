#include "task_manager.h"

void TaskManager::addTask(const std::string& description, int priority) {
    tasks.emplace(description, priority);
}

Task TaskManager::getNextTask() {
    if (tasks.empty()) {
        return Task("", 0);
    }
    
    Task nextTask = tasks.top();
    tasks.pop();
    return nextTask;
}

std::vector<Task> TaskManager::getAllTasks() const {
    std::vector<Task> allTasks;
    std::priority_queue<Task> tempTasks = tasks;
    
    while (!tempTasks.empty()) {
        allTasks.push_back(tempTasks.top());
        tempTasks.pop();
    }
    
    return allTasks;
} 
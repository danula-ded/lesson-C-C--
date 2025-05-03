#pragma once
#include "task.h"
#include <queue>
#include <vector>

class TaskManager {
public:
    // Добавление новой задачи
    void addTask(const std::string& description, int priority);
    
    // Получение задачи с наивысшим приоритетом
    Task getNextTask();
    
    // Проверка наличия задач
    bool hasTasks() const { return !tasks.empty(); }
    
    // Получение всех задач в порядке приоритета
    std::vector<Task> getAllTasks() const;
    
private:
    std::priority_queue<Task> tasks;
}; 
#include "task.h"
#include <sstream>
#include <iomanip>

Task::Task(const std::string& description, int priority)
    : description(description), priority(priority) {}

std::string Task::toString() const {
    std::ostringstream oss;
    oss << "[Приоритет: " << std::setw(2) << priority << "] " << description;
    return oss.str();
} 
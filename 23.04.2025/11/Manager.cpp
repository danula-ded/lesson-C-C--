#include "Manager.h"

double Manager::calculateSalary() const {
    return getBaseSalary() * 1.3; // Менеджеры получают 30% надбавку
} 
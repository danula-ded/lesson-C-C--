#include "events.h"
#include <iostream>
#include <memory>

int main() {
    EventManager manager;
    
    // Add different events to the manager
    manager.addEvent(std::make_unique<MouseEvent>(100, 200));
    manager.addEvent(std::make_unique<KeyboardEvent>('A'));
    manager.addEvent(std::make_unique<MouseEvent>(300, 400));
    manager.addEvent(std::make_unique<KeyboardEvent>('B'));
    manager.addEvent(std::make_unique<MouseEvent>(500, 600));
    
    // Process all events
    std::cout << "Processing all events:" << std::endl;
    manager.processEvents();
    
    return 0;
} 
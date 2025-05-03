#include "game.h"
#include <iostream>
#include <memory>

int main() {
    Game game;
    
    // Add different game objects
    game.addObject(std::make_unique<Player>(100, 100, 100));
    game.addObject(std::make_unique<Enemy>(200, 200, 20));
    game.addObject(std::make_unique<Item>(150, 150, "Зелье здоровья"));
    game.addObject(std::make_unique<Player>(300, 300, 80));
    game.addObject(std::make_unique<Enemy>(400, 400, 30));
    game.addObject(std::make_unique<Item>(250, 250, "Меч"));
    
    // Update all game objects
    std::cout << "Updating all game objects:" << std::endl;
    game.updateAll();
    
    return 0;
} 
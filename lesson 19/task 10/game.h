#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class GameObject {
protected:
    std::string name;
    int x, y;
public:
    GameObject(int x, int y) : x(x), y(y), name("GameObject") {}
    virtual ~GameObject() {}
    virtual void update() = 0;
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }
    void getPosition(int& outX, int& outY) const { outX = x; outY = y; }
};

class Player : public GameObject {
private:
    int health;
public:
    Player(int x, int y, int health) : GameObject(x, y), health(health) {
        name = "Player";
    }
    void update() override {
        std::cout << "Игрок обновляется. Здоровье: " << health 
                  << ", Позиция: (" << x << "," << y << ")" << std::endl;
    }
};

class Enemy : public GameObject {
private:
    int damage;
public:
    Enemy(int x, int y, int damage) : GameObject(x, y), damage(damage) {
        name = "Enemy";
    }
    void update() override {
        std::cout << "Враг обновляется. Урон: " << damage 
                  << ", Позиция: (" << x << "," << y << ")" << std::endl;
    }
};

class Item : public GameObject {
private:
    std::string type;
public:
    Item(int x, int y, const std::string& type) : GameObject(x, y), type(type) {
        name = "Item";
    }
    void update() override {
        std::cout << "Предмет обновляется. Тип: " << type 
                  << ", Позиция: (" << x << "," << y << ")" << std::endl;
    }
};

class Game {
private:
    std::vector<std::unique_ptr<GameObject>> objects;
public:
    void addObject(std::unique_ptr<GameObject> object) {
        objects.push_back(std::move(object));
    }
    
    void updateAll() {
        for (const auto& object : objects) {
            object->update();
        }
    }
};

#endif // GAME_H 
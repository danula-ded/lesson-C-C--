#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Event {
protected:
    std::string name;
public:
    Event() : name("Event") {}
    virtual ~Event() {}
    virtual void handle() = 0;
    void setName(const std::string& newName) { name = newName; }
    std::string getName() const { return name; }
};

class MouseEvent : public Event {
private:
    int x, y;
public:
    MouseEvent(int x, int y) : x(x), y(y) {
        name = "MouseEvent";
    }
    void handle() override {
        std::cout << "Обработка события мыши в координатах (" << x << ", " << y << ")" << std::endl;
    }
};

class KeyboardEvent : public Event {
private:
    char key;
public:
    KeyboardEvent(char k) : key(k) {
        name = "KeyboardEvent";
    }
    void handle() override {
        std::cout << "Обработка события клавиатуры: нажата клавиша '" << key << "'" << std::endl;
    }
};

class EventManager {
private:
    std::vector<std::unique_ptr<Event>> events;
public:
    void addEvent(std::unique_ptr<Event> event) {
        events.push_back(std::move(event));
    }
    
    void processEvents() {
        for (const auto& event : events) {
            event->handle();
        }
    }
};

#endif // EVENTS_H 
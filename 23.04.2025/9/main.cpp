#include "Song.h"
#include "Video.h"
#include <vector>

int main() {
    std::vector<IPlayable*> media;
    
    // Создаем объекты Song и Video
    media.push_back(new Song());
    media.push_back(new Video());
    
    // Вызываем метод play() для каждого объекта
    for (const auto& item : media) {
        item->play();
    }
    
    // Очистка памяти
    for (auto item : media) {
        delete item;
    }
    
    return 0;
} 
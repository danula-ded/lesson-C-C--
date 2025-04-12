#include "rectangle.h"

Rectangle::Rectangle(float width, float height)
    : width(width), height(height) {}

void Rectangle::setWidth(float width) {
    this->width = width;
}

void Rectangle::setHeight(float height) {
    this->height = height;
}

float Rectangle::getWidth() const {
    return width;
}

float Rectangle::getHeight() const {
    return height;
}

float Rectangle::area() const {
    return width * height;
}

float Rectangle::perimeter() const {
    return 2 * (width + height);
} 
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    float width;
    float height;

public:
    Rectangle(float width, float height);

    void setWidth(float width);
    void setHeight(float height);

    float getWidth() const;
    float getHeight() const;

    float area() const;
    float perimeter() const;
};

#endif // RECTANGLE_H 
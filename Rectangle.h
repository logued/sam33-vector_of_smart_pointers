#ifndef INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_RECTANGLE_H
#define INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_RECTANGLE_H

// Rectangle.h		- class definition

#include "Shape.h"

class Rectangle : public Shape {
private:
    int x, y;   // (x,y) of top left corner
    int width, height;

public:
    Rectangle(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    virtual void draw();
    ~Rectangle();
};

#endif //INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_RECTANGLE_H

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <iostream>


class Square : public Shape {
  public:
    Square();
    Square(Vector2 center, Vector2 point);

    virtual ~Square();

    bool inCircle(Vector2 c, double r);
    bool contains(Vector2 p);

    void draw(std::ostream& os, int shift, int s, const char* color) const;
    void print(std::ostream& os) const;
  private:
};

#endif // SQUARE_H

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>

class Circle : public Shape
{
    public:
        Circle();
        Circle(Vector2 center, Vector2 point);
        virtual ~Circle();

        bool inCircle(Vector2 c, double r);
        bool contains(Vector2 p);

        void print(std::ostream& os) const;

    protected:

    private:
};

#endif // CIRCLE_H

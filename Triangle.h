#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"


class Triangle : public Shape
{
    public:
        Triangle();
        Triangle(Vector2 center, Vector2 point);
        virtual ~Triangle();


        bool inCircle(Vector2 c, double r);
        bool contains(Vector2 p);

        void draw(std::ostream& os, int shift, int s, const char* color) const;
        void print(std::ostream& os) const;

    protected:

    private:
};

#endif // TRIANGLE_H

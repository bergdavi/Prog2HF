#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"


class Polygon : public Shape
{
    public:
        Polygon();
        Polygon(Vector2 center, Vector2 point, int sides);
        virtual ~Polygon();

        bool inCircle(Vector2 c, double r);
        bool contains(Vector2 p);

        void print(std::ostream& os) const;

    protected:

    private:
        int sides;
};

#endif // POLYGON_H

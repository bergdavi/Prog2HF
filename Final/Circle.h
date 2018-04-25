/**
 *  \file Circle.h
 *  Circle oszt�ly deklar�ci�ja
 */
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>

/// Circle oszt�ly
/// K�rt t�rol
class Circle : public Shape
{
    public:
        Circle();
        Circle(Vector2 center, Vector2 point);
        virtual ~Circle();

        /// K�r benne van-e egy k�rben
        /// @param c - a k�r k�z�ppontja
        /// @param r - a k�r sugara
        /// @return benne van-e a k�rben
        bool inCircle(Vector2 c, double r);

        /// K�r tartalmaz-e egy pontot
        /// @param p - a k�rd�ses pont
        /// @return tartalmazza-e a pontot
        bool contains(Vector2 p);

        /// K�r rajzol�sa SVG form�tumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltol�s
        /// @param s - nagy�t�s
        /// @param color - sz�n
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// K�r ki�r�sa
        /// @param os - ostream objektum, amire ki�runk
        void print(std::ostream& os) const;

    protected:

    private:
};

#endif // CIRCLE_H

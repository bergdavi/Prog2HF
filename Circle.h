/**
 *  \file Circle.h
 *  Circle osztály deklarációja
 */
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>

/// Circle osztály
/// Kört tárol
class Circle : public Shape
{
    public:
        Circle();
        Circle(Vector2 center, Vector2 point);
        virtual ~Circle();

        /// Kör benne van-e egy körben
        /// @param c - a kör középpontja
        /// @param r - a kör sugara
        /// @return benne van-e a körben
        bool inCircle(Vector2 c, double r);

        /// Kör tartalmaz-e egy pontot
        /// @param p - a kérdéses pont
        /// @return tartalmazza-e a pontot
        bool contains(Vector2 p);

        /// Kör rajzolása SVG formátumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltolás
        /// @param s - nagyítás
        /// @param color - szín
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// Kör kiírása
        /// @param os - ostream objektum, amire kiírunk
        void print(std::ostream& os) const;

    protected:

    private:
};

#endif // CIRCLE_H

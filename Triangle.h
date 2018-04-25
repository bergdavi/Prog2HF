/**
 *  \file Triangle.h
 *  Triangle osztály deklarációja
 */


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

/// Triangle osztály
/// Szabályos háromszöget tárol
class Triangle : public Shape
{
    public:
        Triangle();
        Triangle(Vector2 center, Vector2 point);
        virtual ~Triangle();

        /// Háromszög benne van-e egy körben
        /// @param c - a kör középpontja
        /// @param r - a kör sugara
        /// @return benne van-e a körben
        bool inCircle(Vector2 c, double r);

        /// Háromszög tartalmaz-e egy pontot
        /// @param p - a kérdéses pont
        /// @return tartalmazza-e a pontot
        bool contains(Vector2 p);

        /// Háromszög rajzolása SVG formátumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltolás
        /// @param s - nagyítás
        /// @param color - szín
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// Háromszög kiírása
        /// @param os - ostream objektum, amire kiírunk
        void print(std::ostream& os) const;

    protected:

    private:
};

#endif // TRIANGLE_H

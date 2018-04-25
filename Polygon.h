/**
 *  \file Polygon.h
 *  Polygon osztály deklarációja
 */
#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

/// Sokszög osztály
/// Szabályos sokszöget tárol
class Polygon : public Shape
{
    public:
        Polygon();
        Polygon(Vector2 center, Vector2 point, int sides);
        virtual ~Polygon();

        /// Szabályos sokszög benne van-e egy körben
        /// @param c - a kör középpontja
        /// @param r - a kör sugara
        /// @return benne van-e a körben
        bool inCircle(Vector2 c, double r);

        /// Sokszög tartalmaz-e egy pontot
        /// @param p - a kérdéses pont
        /// @return tartalmazza-e a pontot
        bool contains(Vector2 p);

        /// Sokszög rajzolása SVG formátumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltolás
        /// @param s - nagyítás
        /// @param color - szín
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// Sokszög kiírása
        /// @param os - ostream objektum, amire kiírunk
        void print(std::ostream& os) const;

    protected:

    private:
        int sides;
};

#endif // POLYGON_H

/**
 *  \file Square.h
 *  Square osztály deklarációja
 */
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <iostream>

/// Square osztály
/// Négyzetet tárol
class Square : public Shape {
  public:
    Square();
    Square(Vector2 center, Vector2 point);

    virtual ~Square();

    /// Négyzet benne van-e egy körben
    /// @param c - a kör középpontja
    /// @param r - a kör sugara
    /// @return benne van-e a körben
    bool inCircle(Vector2 c, double r);

    /// Négyzet tartalmaz-e egy pontot
    /// @param p - a kérdéses pont
    /// @return tartalmazza-e a pontot
    bool contains(Vector2 p);

    /// Négyzet rajzolása SVG formátumban
    /// @param os - ostream objektum, amire rajzolunk
    /// @param shift - eltolás
    /// @param s - nagyítás
    /// @param color - szín
    void draw(std::ostream& os, int shift, int s, const char* color) const;

    /// Négyzet kiírása
    /// @param os - ostream objektum, amire kiírunk
    void print(std::ostream& os) const;
  private:
};

#endif // SQUARE_H

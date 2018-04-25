/**
 *  \file Square.h
 *  Square oszt�ly deklar�ci�ja
 */
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <iostream>

/// Square oszt�ly
/// N�gyzetet t�rol
class Square : public Shape {
  public:
    Square();
    Square(Vector2 center, Vector2 point);

    virtual ~Square();

    /// N�gyzet benne van-e egy k�rben
    /// @param c - a k�r k�z�ppontja
    /// @param r - a k�r sugara
    /// @return benne van-e a k�rben
    bool inCircle(Vector2 c, double r);

    /// N�gyzet tartalmaz-e egy pontot
    /// @param p - a k�rd�ses pont
    /// @return tartalmazza-e a pontot
    bool contains(Vector2 p);

    /// N�gyzet rajzol�sa SVG form�tumban
    /// @param os - ostream objektum, amire rajzolunk
    /// @param shift - eltol�s
    /// @param s - nagy�t�s
    /// @param color - sz�n
    void draw(std::ostream& os, int shift, int s, const char* color) const;

    /// N�gyzet ki�r�sa
    /// @param os - ostream objektum, amire ki�runk
    void print(std::ostream& os) const;
  private:
};

#endif // SQUARE_H

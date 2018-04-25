/**
 *  \file Polygon.h
 *  Polygon oszt�ly deklar�ci�ja
 */
#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

/// Soksz�g oszt�ly
/// Szab�lyos soksz�get t�rol
class Polygon : public Shape
{
    public:
        Polygon();
        Polygon(Vector2 center, Vector2 point, int sides);
        virtual ~Polygon();

        /// Szab�lyos soksz�g benne van-e egy k�rben
        /// @param c - a k�r k�z�ppontja
        /// @param r - a k�r sugara
        /// @return benne van-e a k�rben
        bool inCircle(Vector2 c, double r);

        /// Soksz�g tartalmaz-e egy pontot
        /// @param p - a k�rd�ses pont
        /// @return tartalmazza-e a pontot
        bool contains(Vector2 p);

        /// Soksz�g rajzol�sa SVG form�tumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltol�s
        /// @param s - nagy�t�s
        /// @param color - sz�n
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// Soksz�g ki�r�sa
        /// @param os - ostream objektum, amire ki�runk
        void print(std::ostream& os) const;

    protected:

    private:
        int sides;
};

#endif // POLYGON_H

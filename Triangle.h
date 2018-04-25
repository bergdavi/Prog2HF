/**
 *  \file Triangle.h
 *  Triangle oszt�ly deklar�ci�ja
 */


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

/// Triangle oszt�ly
/// Szab�lyos h�romsz�get t�rol
class Triangle : public Shape
{
    public:
        Triangle();
        Triangle(Vector2 center, Vector2 point);
        virtual ~Triangle();

        /// H�romsz�g benne van-e egy k�rben
        /// @param c - a k�r k�z�ppontja
        /// @param r - a k�r sugara
        /// @return benne van-e a k�rben
        bool inCircle(Vector2 c, double r);

        /// H�romsz�g tartalmaz-e egy pontot
        /// @param p - a k�rd�ses pont
        /// @return tartalmazza-e a pontot
        bool contains(Vector2 p);

        /// H�romsz�g rajzol�sa SVG form�tumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltol�s
        /// @param s - nagy�t�s
        /// @param color - sz�n
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// H�romsz�g ki�r�sa
        /// @param os - ostream objektum, amire ki�runk
        void print(std::ostream& os) const;

    protected:

    private:
};

#endif // TRIANGLE_H

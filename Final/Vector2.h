/**
 *  \file Vector2.h
 *  Vector2 osztály deklarációja
 */
#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <sstream>

/// Vector2 osztály
/// Kétdimenziós vektort tárol
class Vector2
{
    public:
        Vector2();
        Vector2(double x, double y);
        virtual ~Vector2();

        /// X getter
        /// @return a vektor X koordinátája
        double getX() const;

        /// Y getter
        /// @return a vektor Y koordinátája
        double getY() const;

        /// X setter
        /// @param x - a vektor új X koordinátája
        void setX(double x);

        /// Y setter
        /// @param x - a vektor új X koordinátája
        void setY(double y);

        /// A pont egy tetszöleges egyenes felett van-e
        /// @param p1 - az egyenes 1. pontja
        /// @param p2 - az egyenes 2. pontja
        /// @return 1 ha a pont az egyenes felett van, -1 ha az egyenes alatt, 0 ha az egyenesen
        int aboveLine(Vector2 p1, Vector2 p2);

        /// Egy szakasz egy tetszöleges körön belül van-e
        /// @param p1 - a szakasz végpontja
        /// @param o - a kör középpontja
        /// @param r - a kör sugara
        /// @return A szakasz a körön belül van-e
        bool inCircle(Vector2 p1, Vector2 o, double r);

        /// A pont elforgatása egy másik pont körül
        /// @param p - e körül a pont körül forgatunk
        /// @param angle - az elforgatás szöge radiánban
        /// @return Az elforgatott pont
        Vector2 rotateAround(Vector2 p, double angle);

        /// Vektor hosszának kiszámítása
        /// @param p - a vektor
        /// @return A vektor hossza
        friend double abs(Vector2 p);

        /// - operator
        /// @param v - vektor
        /// @return A két vektor különbsége
        Vector2 operator-(const Vector2& v) const;

        /// + operator
        /// @param v - vektor
        /// @return A két vektor összege
        Vector2 operator+(const Vector2& v) const;

        /// / operator
        /// @param d - valós szorzó
        /// @return A vektor 1/d-szerese
        Vector2 operator/(double d) const;

        /// * operator
        /// @param d - valós szorzó
        /// @return A vektor d-szerese
        Vector2 operator*(double d) const;

        /// == operator
        /// @param v - összehasonlítandó vektor
        /// @return A két vektor azonos-e
        bool operator==(Vector2& v) const;

        /// Vektor rajzolása SVG formátumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltolás
        /// @param s - nagyítás
        /// @param color - szín
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// >> operator
        /// @param is - istream objektum, amiröl beolvasunk
        /// @param s - ahova beolvasunk
        friend std::istream& operator>> (std::istream& is, Vector2& s);

        /// << operator
        /// @param os - ostream objektum, amire kiírunk
        /// @param s - amit kiírunk
        friend std::ostream& operator<< (std::ostream& os, const Vector2& s);

    protected:

    private:
        double x;   ///< x koordináta
        double y;   ///< y koordináta
};






#endif // VECTOR2_H

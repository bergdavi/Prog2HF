/**
 *  \file Vector2.h
 *  Vector2 oszt�ly deklar�ci�ja
 */
#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <sstream>

/// Vector2 oszt�ly
/// K�tdimenzi�s vektort t�rol
class Vector2
{
    public:
        Vector2();
        Vector2(double x, double y);
        virtual ~Vector2();

        /// X getter
        /// @return a vektor X koordin�t�ja
        double getX() const;

        /// Y getter
        /// @return a vektor Y koordin�t�ja
        double getY() const;

        /// X setter
        /// @param x - a vektor �j X koordin�t�ja
        void setX(double x);

        /// Y setter
        /// @param x - a vektor �j X koordin�t�ja
        void setY(double y);

        /// A pont egy tetsz�leges egyenes felett van-e
        /// @param p1 - az egyenes 1. pontja
        /// @param p2 - az egyenes 2. pontja
        /// @return 1 ha a pont az egyenes felett van, -1 ha az egyenes alatt, 0 ha az egyenesen
        int aboveLine(Vector2 p1, Vector2 p2);

        /// Egy szakasz egy tetsz�leges k�r�n bel�l van-e
        /// @param p1 - a szakasz v�gpontja
        /// @param o - a k�r k�z�ppontja
        /// @param r - a k�r sugara
        /// @return A szakasz a k�r�n bel�l van-e
        bool inCircle(Vector2 p1, Vector2 o, double r);

        /// A pont elforgat�sa egy m�sik pont k�r�l
        /// @param p - e k�r�l a pont k�r�l forgatunk
        /// @param angle - az elforgat�s sz�ge radi�nban
        /// @return Az elforgatott pont
        Vector2 rotateAround(Vector2 p, double angle);

        /// Vektor hossz�nak kisz�m�t�sa
        /// @param p - a vektor
        /// @return A vektor hossza
        friend double abs(Vector2 p);

        /// - operator
        /// @param v - vektor
        /// @return A k�t vektor k�l�nbs�ge
        Vector2 operator-(const Vector2& v) const;

        /// + operator
        /// @param v - vektor
        /// @return A k�t vektor �sszege
        Vector2 operator+(const Vector2& v) const;

        /// / operator
        /// @param d - val�s szorz�
        /// @return A vektor 1/d-szerese
        Vector2 operator/(double d) const;

        /// * operator
        /// @param d - val�s szorz�
        /// @return A vektor d-szerese
        Vector2 operator*(double d) const;

        /// == operator
        /// @param v - �sszehasonl�tand� vektor
        /// @return A k�t vektor azonos-e
        bool operator==(Vector2& v) const;

        /// Vektor rajzol�sa SVG form�tumban
        /// @param os - ostream objektum, amire rajzolunk
        /// @param shift - eltol�s
        /// @param s - nagy�t�s
        /// @param color - sz�n
        void draw(std::ostream& os, int shift, int s, const char* color) const;

        /// >> operator
        /// @param is - istream objektum, amir�l beolvasunk
        /// @param s - ahova beolvasunk
        friend std::istream& operator>> (std::istream& is, Vector2& s);

        /// << operator
        /// @param os - ostream objektum, amire ki�runk
        /// @param s - amit ki�runk
        friend std::ostream& operator<< (std::ostream& os, const Vector2& s);

    protected:

    private:
        double x;   ///< x koordin�ta
        double y;   ///< y koordin�ta
};






#endif // VECTOR2_H

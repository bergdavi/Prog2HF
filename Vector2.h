#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

class Vector2
{
    public:
        Vector2();
        Vector2(double x, double y);
        virtual ~Vector2();

        double getX() const;
        double getY() const;
        void setX(double x);
        void setY(double y);

        int aboveLine(Vector2 p1, Vector2 p2);
        bool inCircle(Vector2 p1, Vector2 o, double r);

        Vector2 rotateAround(Vector2 p, double angle);

        friend double abs(Vector2 p);

        Vector2 operator-(const Vector2& v) const;
        Vector2 operator+(const Vector2& v) const;
        Vector2 operator/(double d) const;
        Vector2 operator*(double d) const;

        friend std::istream& operator>> (std::istream& is, Vector2& s);
        friend std::ostream& operator<< (std::ostream& os, const Vector2& s);

    protected:

    private:
        double x;
        double y;
};






#endif // VECTOR2_H

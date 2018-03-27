#include "Vector2.h"
#include <math.h>

Vector2::Vector2(): x(0), y(0) {}

Vector2::Vector2(double x, double y): x(x), y(y) {}

double Vector2::getX() const {
    return x;
}

double Vector2::getY() const {
    return y;
}

void Vector2::setX(double x) {
    this->x = x;
}

void Vector2::setY(double y) {
    this->y = y;
}

int Vector2::aboveLine(Vector2 p1, Vector2 p2) {
    Vector2 v = p1-p2;
    double m = v.getY()/v.getX();
    double b = p1.getY()-p1.getX()*m;
    double above = y-(m*x+b);
    if(above > 0) return 1;
    if(above < 0) return -1;
    return 0;
}

Vector2 Vector2::rotateAround(Vector2 p, double angle) {
    Vector2 n = Vector2(x,y)-p;
    double s = sin(angle);
    double c = cos(angle);

    double newx = n.getX()*c-n.getY()*s;
    double newy = n.getX()*s-n.getY()*c;

    return Vector2(newx, newy) + p;
}

double abs(Vector2 p) {
    return sqrt(p.x*p.x + p.y*p.y);
}

Vector2 Vector2::operator-(const Vector2& v) const {
    Vector2 n(x-v.x, y-v.y);
    return n;
}

Vector2 Vector2::operator+(const Vector2& v) const {
    Vector2 n(x+v.x, y+v.y);
    return n;
}


std::ostream& operator<< (std::ostream& os, const Vector2& s) {
    return os << "(" << s.x << "," << s.y << ")";
}

std::istream& operator>> (std::istream& is, Vector2& s) {
    char c;
    is >> c >> s.x >> c >> s.y >> c;
    return is;
}



Vector2::~Vector2() {
    //dtor
}

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
    if(v.getX() == 0){
        if(p1.x > x){
            return -1;
        }
        if(p1.x < x) {
            return 1;
        }
        return 0;
    }
    double m = v.getY()/v.getX();
    double b = p1.getY()-p1.getX()*m;
    double above = y-(m*x+b);
    if(above > 0) return 1;
    if(above < 0) return -1;
    return 0;
}

bool Vector2::inCircle(Vector2 p1, Vector2 o, double r) {
    if(abs(*this-o) <= r || abs(p1-o) <= r) {
        return true;
    }
    Vector2 v1 = o-*this;
    Vector2 v2 = p1-*this;
    double angle = atan2(v1.y, v1.x) - atan2(v2.y, v2.x);

    double rat = abs(v1)*cos(angle) / abs(v2);
    if(rat < 0 || rat > 1){
        return false;
    }

    Vector2 intersect = *this+(v2*rat);

    return abs(intersect-o) <= r;
}

Vector2 Vector2::rotateAround(Vector2 p, double angle) {
    Vector2 n = Vector2(x,y)-p;
    double s = sin(angle);
    double c = cos(angle);

    double newx = n.getX()*c-n.getY()*s;
    double newy = n.getX()*s+n.getY()*c;

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

Vector2 Vector2::operator/(double d) const {
    Vector2 n(x/d, y/d);
    return n;
}

Vector2 Vector2::operator*(double d) const {
    Vector2 n(x*d, y*d);
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

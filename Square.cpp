#include "Square.h"
#include <iostream>

Square::Square():Shape() {}
Square::Square(Vector2 center, Vector2 point):Shape(center, point) {
    double a = abs(center - point)*2/sqrt(2);
    area = a*a;
    circumference = 4*a;
}
Square::~Square()
{
    //dtor
}

bool Square::inCircle(Vector2 c, double r) {
    return false;
}
bool Square::contains(Vector2 p) {
    Vector2 t = point;
    Vector2 t1 = point.rotateAround(center, M_PI_2);
    for(int i = 0; i < 4; i++){
        int a = p.aboveLine(t, t1);
        if(a != 0 && a != center.aboveLine(t,t1)){
            return false;
        }
        t = t.rotateAround(center, M_PI_2);
        t1 = t1.rotateAround(center, M_PI_2);
    }
    return true;
}

void Square::print(std::ostream& os) const{
    os << "Square " << center << " " << point;
}

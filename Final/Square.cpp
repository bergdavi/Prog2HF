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
    Vector2 t = point;
    Vector2 t1 = point.rotateAround(center, M_PI*2/4);
    bool inC = true;
    for(int i = 0; i < 4; i++){
        int a = c.aboveLine(t, t1);
        if(a != center.aboveLine(t,t1)){
            inC = false;
        }

        if(t.inCircle(t1, c, r)){
            return true;
        }

        t = t.rotateAround(center, M_PI*2/4);
        t1 = t1.rotateAround(center, M_PI*2/4);

    }
    return inC;
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


void Square::draw(std::ostream& os, int shift, int s, const char* color = "black") const{
    os << "<polyline points=\"";
    Vector2 t = point;
    for(int i = 0; i < 5; i++){
        os << (t.getX()*s)+shift << " " << (-t.getY()*s)+shift;
        if(i < 4){
            os << ", ";
        }
        t = t.rotateAround(center, M_PI*2/4);

    }
    os << "\" stroke=\"" << color << "\" stroke-width=\"2\" fill=\"transparent\"/>" << std::endl;

}

void Square::print(std::ostream& os) const{
    os << "Square " << center << " " << point;

}

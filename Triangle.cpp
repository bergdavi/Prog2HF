#include "Triangle.h"
#include <iostream>



Triangle::Triangle():Shape() {}
Triangle::Triangle(Vector2 center, Vector2 point):Shape(center, point) {
    double a = abs(center-point)*3/sqrt(3);
    area = 1.0/4*sqrt(3)*a*a;
    circumference = 3*a;
}

Triangle::~Triangle()
{
    //dtor
}

bool Triangle::inCircle(Vector2 c, double r) {
    Vector2 t = point;
    Vector2 t1 = point.rotateAround(center, M_PI*2/3);
    bool inC = true;
    for(int i = 0; i < 3; i++){
        int a = c.aboveLine(t, t1);
        if(a != center.aboveLine(t,t1)){
            inC = false;
        }

        if(t.inCircle(t1, c, r)){
            return true;
        }

        t = t.rotateAround(center, M_PI*2/3);
        t1 = t1.rotateAround(center, M_PI*2/3);

    }
    return inC;
}
bool Triangle::contains(Vector2 p) {
    Vector2 t = point;
    Vector2 t1 = point.rotateAround(center, M_PI*2/3);
    for(int i = 0; i < 3; i++){
        int a = p.aboveLine(t, t1);
        if(a != 0 && a != center.aboveLine(t,t1)){
            return false;
        }
        t = t.rotateAround(center, M_PI*2/3);
        t1 = t1.rotateAround(center, M_PI*2/3);
    }
    return true;
}

void Triangle::draw(std::ostream& os, int shift, int s, const char* color = "black") const {
    os << "<polyline points=\"";
    Vector2 t = point;
    for(int i = 0; i < 4; i++){
        os << (t.getX()*s)+shift << " " << (-t.getY()*s)+shift;
        if(i < 3){
            os << ", ";
        }
        t = t.rotateAround(center, M_PI*2/3);
    }
    os << "\" stroke=\"" << color << "\" stroke-width=\"2\" fill=\"transparent\"/>" << std::endl;
}
void Triangle::print(std::ostream& os) const {
    os << "Triangle " << center << " " << point;
}

#include "Polygon.h"

Polygon::Polygon():Shape(), sides(0) {}

Polygon::Polygon(Vector2 center, Vector2 point, int sides):Shape(center, point), sides(sides) {
    double r = abs(center-point);
    area = 0.5*sides*r*r*sin(2*M_PI/sides);
    circumference = sides*2*r*sin(M_PI/sides);
}

bool Polygon::inCircle(Vector2 c, double r) {
    Vector2 t = point;
    Vector2 t1 = point.rotateAround(center, M_PI*2/sides);
    bool inC = true;
    for(int i = 0; i < sides; i++){
        int a = c.aboveLine(t, t1);
        if(a != center.aboveLine(t,t1)){
            inC = false;
        }

        if(t.inCircle(t1, c, r)){
            return true;
        }

        t = t.rotateAround(center, M_PI*2/sides);
        t1 = t1.rotateAround(center, M_PI*2/sides);

    }
    return inC;
}
bool Polygon::contains(Vector2 p) {
    Vector2 t = point;
    Vector2 t1 = point.rotateAround(center, M_PI*2/sides);
    for(int i = 0; i < sides; i++){
        int a = p.aboveLine(t, t1);
        if(a != 0 && a != center.aboveLine(t,t1)){
            return false;
        }
        t = t.rotateAround(center, M_PI*2/sides);
        t1 = t1.rotateAround(center, M_PI*2/sides);
    }
    return true;
}

void Polygon::draw(std::ostream& os, int shift, int s, const char* color = "black") const {
    os << "<polyline points=\"";
    Vector2 t = point;
    for(int i = 0; i < sides+1; i++){
        os << (t.getX()*s)+shift << " " << (-t.getY()*s)+shift;
        if(i < sides){
            os << ", ";
        }
        t = t.rotateAround(center, M_PI*2/sides);
    }
    os << "\" stroke=\"" << color << "\" stroke-width=\"2\" fill=\"transparent\"/>" << std::endl;
}
void Polygon::print(std::ostream& os) const {
    os << "Polygon " << center << " " << point << " " << sides;
}

Polygon::~Polygon()
{
    //dtor
}

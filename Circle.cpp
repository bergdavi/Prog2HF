
#include "Circle.h"

#include <iostream>

Circle::Circle():Shape() {}
Circle::Circle(Vector2 center, Vector2 point):Shape(center, point) {
    double r = abs(center-point);
    area = r*r*M_PI;
    circumference = 2*r*M_PI;
}

Circle::~Circle()
{
    //dtor
}


bool Circle::inCircle(Vector2 c, double r) {
    return abs(c-center) <= r+abs(center-point);
}
bool Circle::contains(Vector2 p) {
    return abs(center-point) >= abs(center-p);
}

void Circle::print(std::ostream& os) const{
    os << "Circle " << center << " " << point;
}

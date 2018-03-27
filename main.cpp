#include <iostream>
#include "Vector2.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"

using namespace std;

int main()
{
    ShapeList sl = ShapeList();
    sl.add(new Square(Vector2(0,0), Vector2(10,20)));
    sl.add(new Triangle(Vector2(-40, -35), Vector2(-32, -73)));
    sl.add(new Circle(Vector2(50, 50), Vector2(70, 30)));
    cout << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"1000\" height=\"1000\">" <<endl;
    cout << *sl.first() << endl;
    while(sl.next() != NULL){
        cout << *sl.iter << endl;
    }
    cout << "</svg>" << endl;



//    Shape *s;
//    while(cin >> s){
//        cout << *s << " area:" << s->getArea() << endl;
//        delete s;
//    }


//    cout << Vector2(0,0).aboveLine(Vector2(-1,-1), Vector2(1,1)) << endl;

//    cout << Vector2(0,1).rotateAround(Vector2(0,0), M_PI_2) << endl;



//    Shape *s = new Polygon(Vector2(0,0), Vector2(1,0), 4);
//    cout << s->contains(Vector2(1, 0.3)) << endl;


//    Vector2 p1(0,0);
//    Vector2 p2(0,10);
//    Vector2 circle(5,5);
//
//    cout << (p1.inCircle(p2, circle, 6)?"y":"n") << endl;

    cout << "done" << endl;
    return 0;
}

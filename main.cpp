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
//    ShapeList sl = ShapeList();
//    sl.add(new Square());
//    sl.add(new Triangle());
//    sl.add(new Circle());
//    sl.add(new Square(Vector2(1,2), Vector2(3,4)));
//    sl.add(new Triangle(Vector2(-0.5, 9), Vector2(34, -1)));
//    sl.add(new Circle(Vector2(32, 23), Vector2(-3, -9)));
//    cout << sl.getLength() << endl;
//    cout << *sl.first() << endl;
//    while(sl.next() != NULL){
//        cout << *sl.iter << endl;
//    }



//    Shape *s;
//    while(cin >> s){
//        cout << *s << " area:" << s->getArea() << endl;
//        delete s;
//    }


//    cout << Vector2(0,0).aboveLine(Vector2(-1,-1), Vector2(1,1)) << endl;

//    cout << Vector2(0,1).rotateAround(Vector2(0,0), M_PI_2) << endl;
    Shape *s = new Polygon(Vector2(0,0), Vector2(1,0), 4);
    cout << s->contains(Vector2(1, 0.3)) << endl;


    cout << "done" << endl;
    return 0;
}

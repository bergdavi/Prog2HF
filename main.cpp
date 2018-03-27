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
    int drawSize = 100;
    int canvasSize = 1000;



    ShapeList sl = ShapeList();
    sl.add(new Polygon(Vector2(1, 2.67), Vector2(3,3), 7));
    //sl.add(new Triangle(Vector2(0, 0), Vector2(0, 1.3)));
    //sl.add(new Circle(Vector2(0, 0), Vector2(0, 0.5)));
    //sl.add(new Polygon(Vector2(0, 0), Vector2(0, 4), 10));
    cout << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"" << canvasSize << "\" height=\"" << canvasSize << "\">" <<endl;
    cout << "<line x1=\"" << canvasSize/2 << "\" x2=\"" << canvasSize/2 << "\" y1=\"0\" y2=\"" << canvasSize << "\" stroke=\"red\" stroke-width=\"2\" fill=\"red\"/>" << endl;
    cout << "<line x1=\"0\" x2=\"" << canvasSize << "\" y1=\"" << canvasSize/2 << "\" y2=\"" << canvasSize/2 << "\" stroke=\"red\" stroke-width=\"2\" fill=\"red\"/>" << endl;
    cout << "<circle cx=\"" << canvasSize/2 << "\" cy=\"" << canvasSize/2 << "\" r=\"" << drawSize << "\" stroke=\"red\" fill=\"transparent\" stroke-width=\"2\"/>" << endl;
    for(Shape* s = sl.first(); s != NULL; s = sl.next()){
        s->draw(cout, 500, 100);
    }
    cout << "</svg>" << endl;




    for(Shape* s = sl.first(); s != NULL; s = sl.next()){
        cout << s->inCircle(Vector2(0,0), 1) << endl;
    }

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

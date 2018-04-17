#include <iostream>
#include <fstream>
#include "Vector2.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "gtest_lite.h"

using namespace std;

int main()
{
    bool drawShapes = true;

    int drawSize = 100;
    int canvasSize = 1000;






    ifstream inputFile;
    inputFile.exceptions ( ifstream::failbit | ifstream::badbit );
    try {
        inputFile.open("in.txt");
    }
    catch(const ifstream::failure& e) {
        cerr << "Could not open input file!" << endl;
        return 1;
    }

    ofstream svgFile;
    svgFile.exceptions ( ifstream::failbit | ifstream::badbit );
    if(drawShapes) {
        try {
        svgFile.open("drawing.svg");
        }
        catch(const ofstream::failure& e) {
            drawShapes = false;
            cerr << "Could not open svg file!" << endl;
        }
    }



    ShapeList sl = ShapeList();

    Shape *s;
    while(inputFile >> s){
        sl.add(s);
    }
    inputFile.close();


//    sl.add(new Polygon(Vector2(1, 2.69), Vector2(3,3), 7));
//    sl.add(new Triangle(Vector2(0, 0), Vector2(0, 1.3)));
//    sl.add(new Triangle(Vector2(-2, 2), Vector2(-0.71, 0.71)));
//    sl.add(new Circle(Vector2(1.6, 0), Vector2(1.6, 0.5)));
//    sl.add(new Square(Vector2(-0.8, -1.5), Vector2(-0.75, -0.75)));
//    sl.add(new Square(Vector2(0, -1.9), Vector2(-1, -0.9)));
//    sl.add(new Polygon(Vector2(2, 0), Vector2(2, 3), 10));
    if(drawShapes) {
        svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"" << canvasSize << "\" height=\"" << canvasSize << "\">" <<endl;

        for(Shape* s = sl.first(); s != NULL; s = sl.next()){
            if( s->inCircle(Vector2(0,0), 1)){
                s->draw(svgFile, 500, 100, "red");
            }
            else{
                s->draw(svgFile, 500, 100, "green");
            }

        }

        Vector2(0.2,0.2).draw(svgFile, 500, 100, "black");

        svgFile << "<line x1=\"" << canvasSize/2 << "\" x2=\"" << canvasSize/2 << "\" y1=\"0\" y2=\"" << canvasSize << "\" stroke=\"blue\" stroke-width=\"2\" fill=\"red\" stroke-dasharray=\"10,10\"/>" << endl;
        svgFile << "<line x1=\"0\" x2=\"" << canvasSize << "\" y1=\"" << canvasSize/2 << "\" y2=\"" << canvasSize/2 << "\" stroke=\"blue\" stroke-width=\"2\" fill=\"red\" stroke-dasharray=\"10,10\"/>" << endl;
        svgFile << "<circle cx=\"" << canvasSize/2 << "\" cy=\"" << canvasSize/2 << "\" r=\"" << drawSize << "\" stroke=\"blue\" fill=\"transparent\" stroke-width=\"2\" stroke-dasharray=\"10,10\"/>" << endl;
        svgFile << "</svg>" << endl;

        svgFile.close();
    }


    TEST(Test1, emptyStr) {
      Shape* s = new Square(Vector2(0,0), Vector2(1,1));
      EXPECT_EQ(4.0, s->getArea()) << "Nem jo a terulet" << endl;
      EXPECT_EQ(8.0, s->getCircumference()) << "Nem jo a Kerulet" << endl;

    } ENDM




//    for(Shape* s = sl.first(); s != NULL; s = sl.next()){
//        cout << s->inCircle(Vector2(0,0), 1) << endl;
//    }

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

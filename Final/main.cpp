#include <iostream>
#include <fstream>
#include "Vector2.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "gtest_lite.h"

#define drawShapes


using namespace std;



int main()
{
#ifdef drawShapes
    int drawSize = 100;
    int canvasSize = 1000;
#endif // drawShapes

    ifstream inputFile;
    inputFile.exceptions ( ifstream::failbit | ifstream::badbit );
    try {
        inputFile.open("in.txt");
        inputFile.exceptions(ifstream::goodbit);
    }
    catch(const ifstream::failure& e) {
        cerr << "Could not open input file!" << endl;
        return 1;
    }

#ifdef drawShapes
    ofstream svgFile;
    svgFile.exceptions ( ofstream::failbit | ofstream::badbit );

    try {
    svgFile.open("drawing.svg");
    }
    catch(const ofstream::failure& e) {
        cerr << "Could not open svg file!" << endl;
        return 1;
    }
    svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"" << canvasSize << "\" height=\"" << canvasSize << "\">" <<endl;

#endif // drawShapes

    ShapeList sl = ShapeList();

    Shape *s;
    while(inputFile >> s){
        if(!s->inCircle(Vector2(0,0), 1)) {
            sl.add(s);
        }
        else {
            delete s;
        }
    }
    inputFile.close();

    Vector2 v;
    while(cin >> v) {
#ifdef drawShapes
        v.draw(svgFile, canvasSize/2, drawSize, "black");
#endif // drawShapes
        cout << v << ":" << endl;
        for(Shape* s = sl.first(); s != NULL; s = sl.next()){
            if(s->contains(v)) {
                cout << *s << endl;
            }
        }

    }



#ifdef drawShapes
    for(Shape* s = sl.first(); s != NULL; s = sl.next()){
        if( s->inCircle(Vector2(0,0), 1)){
            s->draw(svgFile, canvasSize/2, drawSize, "red");
        }
        else{
            s->draw(svgFile, canvasSize/2, drawSize, "green");
        }
    }

    Vector2(0.2,0.2).draw(svgFile, canvasSize/2, drawSize, "black");

    svgFile << "<line x1=\"" << canvasSize/2 << "\" x2=\"" << canvasSize/2 << "\" y1=\"0\" y2=\"" << canvasSize << "\" stroke=\"blue\" stroke-width=\"2\" fill=\"red\" stroke-dasharray=\"10,10\"/>" << endl;
    svgFile << "<line x1=\"0\" x2=\"" << canvasSize << "\" y1=\"" << canvasSize/2 << "\" y2=\"" << canvasSize/2 << "\" stroke=\"blue\" stroke-width=\"2\" fill=\"red\" stroke-dasharray=\"10,10\"/>" << endl;
    svgFile << "<circle cx=\"" << canvasSize/2 << "\" cy=\"" << canvasSize/2 << "\" r=\"" << drawSize << "\" stroke=\"blue\" fill=\"transparent\" stroke-width=\"2\" stroke-dasharray=\"10,10\"/>" << endl;
    svgFile << "</svg>" << endl;

    svgFile.close();
#endif // drawShapes



    ShapeList sl_test = ShapeList();
	Shape* shape;
	Vector2 vec;

	sl_test.add(new Circle(Vector2(0, 0), Vector2(0, 1)));
	sl_test.add(new Triangle(Vector2(0, 0), Vector2(0, 2)));
	sl_test.add(new Square(Vector2(1, 1), Vector2(0,0)));
	sl_test.add(new Polygon(Vector2(2, -1), Vector2(2, 3), 10));

	TEST(Lista, Elemszam) {
		EXPECT_EQ(4, sl_test.getLength()) << "Nem jo az elemszam" << endl;
		EXPECT_THROW(sl_test.get(10), std::out_of_range) << "Nem jo a kivetelkezeles" << endl;
	} ENDM

	TEST(Negyzet, Terulet-Kerulet) {
		EXPECT_DOUBLE_EQ(4.0, sl_test.get(2)->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(8.0, sl_test.get(2)->getCircumference()) << "Nem jo a Kerulet" << endl;
	} ENDM

	TEST(Kor, Terulet-Kerulet) {
		shape = new Circle(Vector2(1,1), Vector2(2,1));
		EXPECT_DOUBLE_EQ(M_PI, shape->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(2*M_PI, shape->getCircumference()) << "Nem jo a Kerulet" << endl;
		delete shape;
	} ENDM

	TEST(Haromszog, Terulet-Kerulet) {
		shape = new Triangle(Vector2(0,0), Vector2(0,2));
		EXPECT_DOUBLE_EQ(1.0/4.0*sqrt(3)*12.0, shape->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(6*sqrt(3), shape->getCircumference()) << "Nem jo a Kerulet" << endl;
		delete shape;
	} ENDM

	TEST(Sokszog, Terulet-Kerulet) {
		shape = new Polygon(Vector2(0,0), Vector2(0,2), 6);
		EXPECT_DOUBLE_EQ(12.0*sin(M_PI/3), shape->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(24.0*sin(M_PI/6), shape->getCircumference()) << "Nem jo a Kerulet" << endl;
		delete shape;
	} ENDM

	TEST(Alakzatok, Beolvas-kiir) {
		std::stringstream is;
		std::string temp = "Circle (1,1) (2,1)";
		is << temp;
		is >> shape;
		cout << "\tBemenet: " << temp << "\n" << "\tKimenet: " << *shape << endl;
		delete shape;
		temp = "Triangle (-1,4) (2.3,1)";
		is << temp;
		is >> shape;
		cout << "\n\tBemenet: " << temp << "\n" << "\tKimenet: " << *shape << endl;
		delete shape;
		temp = "Square (2,4.2) (3.1,-1.1)";
		is << temp;
		is >> shape;
		cout << "\n\tBemenet: " << temp << "\n" << "\tKimenet: " << *shape << endl;
		delete shape;
		temp = "Polygon (4,2) (-2,1.5) 7";
		is << temp;
		is >> shape;
		cout << "\n\tBemenet: " << temp << "\n" << "\tKimenet: " << *shape << endl;
		delete shape;

	} ENDM

	TEST(Vektor, X-Y-abs) {
		vec = Vector2(2,3);
		EXPECT_DOUBLE_EQ(2.0, vec.getX()) << "Nem jo az X koordinata" << endl;
		EXPECT_DOUBLE_EQ(3.0, vec.getY()) << "Nem jo az Y koordinata" << endl;
		EXPECT_DOUBLE_EQ(sqrt(13), abs(vec)) << "Nem jo az Y koordinata" << endl;
	} ENDM

	TEST(Vektor, operatorok) {
		vec = Vector2(1,2);
		EXPECT_EQ(Vector2(3,4), vec+Vector2(2,2)) << "Nem jo az osszeadas" << endl;
		EXPECT_EQ(Vector2(0,0), vec-Vector2(1,2)) << "Nem jo a kivonas" << endl;
		EXPECT_EQ(Vector2(2,4), vec*2) << "Nem jo a szorzas" << endl;
		EXPECT_EQ(Vector2(0.5,1), vec/2) << "Nem jo az osztas" << endl;

	} ENDM

	TEST(Vektor, aboveLine) {
		vec = Vector2(2,3);
		EXPECT_EQ(1, vec.aboveLine(Vector2(0,0), Vector2(5,0))) << "Nem jo az aboveLine" << endl;
		EXPECT_EQ(-1, vec.aboveLine(Vector2(0,5), Vector2(5,5))) << "Nem jo az aboveLine" << endl;
		EXPECT_EQ(0, vec.aboveLine(Vector2(0,0), Vector2(4,6))) << "Nem jo az aboveLine" << endl;

	} ENDM

	TEST(Vektor, beolvasas) {
		std::stringstream is;
		is << Vector2(3,4);
		is >> vec;
		EXPECT_EQ(Vector2(3,4), vec) << "Nem jo a beolvasas/kiiras" << endl;
	} ENDM

    return 0;
}

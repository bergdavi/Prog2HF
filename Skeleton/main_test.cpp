// Berghammer David
// EB2DYD


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

    



    ShapeList sl = ShapeList();
	Shape* shape;
	Vector2 v;
	
	sl.add(new Circle(Vector2(0, 0), Vector2(0, 1)));	
	sl.add(new Triangle(Vector2(0, 0), Vector2(0, 2)));		
	sl.add(new Square(Vector2(1, 1), Vector2(0,0)));	
	sl.add(new Polygon(Vector2(2, -1), Vector2(2, 3), 10));
	
	TEST(Lista, Elemszam) {
		EXPECT_EQ(4, sl.getLength()) << "Nem jo az elemszam" << endl;
		EXPECT_THROW(sl.get(10), std::out_of_range) << "Nem jo a kivetelkezeles" << endl;
	} ENDM
	
	TEST(Terulet-Kerulet, Negyzet) {
		EXPECT_DOUBLE_EQ(4.0, sl.get(2)->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(8.0, sl.get(2)->getCircumference()) << "Nem jo a Kerulet" << endl;
	} ENDM	
	
	TEST(Terulet-Kerulet, Kor) {
		shape = new Circle(Vector2(1,1), Vector2(2,1));
		EXPECT_DOUBLE_EQ(M_PI, shape->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(2*M_PI, shape->getCircumference()) << "Nem jo a Kerulet" << endl;
		delete shape;
	} ENDM
	
	TEST(Terulet-Kerulet, Haromszog) {
		shape = new Triangle(Vector2(0,0), Vector2(0,2));
		EXPECT_DOUBLE_EQ(1.0/4.0*sqrt(3)*12.0, shape->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(6*sqrt(3), shape->getCircumference()) << "Nem jo a Kerulet" << endl;
		delete shape;
	} ENDM
	
	TEST(Terulet-Kerulet, Sokszog) {
		shape = new Polygon(Vector2(0,0), Vector2(0,2), 6);
		EXPECT_DOUBLE_EQ(12.0*sin(M_PI/3), shape->getArea()) << "Nem jo a terulet" << endl;
		EXPECT_DOUBLE_EQ(24.0*sin(M_PI/6), shape->getCircumference()) << "Nem jo a Kerulet" << endl;
		delete shape;
	} ENDM
	
	TEST(Beolvas-kiir, Alakzatok) {		
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
		v = Vector2(2,3);
		EXPECT_DOUBLE_EQ(2.0, v.getX()) << "Nem jo az X koordinata" << endl;
		EXPECT_DOUBLE_EQ(3.0, v.getY()) << "Nem jo az Y koordinata" << endl;
		EXPECT_DOUBLE_EQ(sqrt(13), abs(v)) << "Nem jo az Y koordinata" << endl;
	} ENDM
	
	TEST(Vektor, operatorok) {
		v = Vector2(1,2);
		EXPECT_EQ(Vector2(3,4), v+Vector2(2,2)) << "Nem jo az osszeadas" << endl;
		EXPECT_EQ(Vector2(0,0), v-Vector2(1,2)) << "Nem jo a kivonas" << endl;
		EXPECT_EQ(Vector2(2,4), v*2) << "Nem jo a szorzas" << endl;
		EXPECT_EQ(Vector2(0.5,1), v/2) << "Nem jo az osztas" << endl;
		
	} ENDM
	
	TEST(Vektor, aboveLine) {
		v = Vector2(2,3);
		EXPECT_EQ(1, v.aboveLine(Vector2(0,0), Vector2(5,0))) << "Nem jo az aboveLine" << endl;
		EXPECT_EQ(-1, v.aboveLine(Vector2(0,5), Vector2(5,5))) << "Nem jo az aboveLine" << endl;
		EXPECT_EQ(0, v.aboveLine(Vector2(0,0), Vector2(4,6))) << "Nem jo az aboveLine" << endl;
		
	} ENDM
	
	TEST(Vektor, beolvasas) {		
		std::stringstream is;
		is << Vector2(3,4);
		is >> v;
		EXPECT_EQ(Vector2(3,4), v) << "Nem jo a beolvasas/kiiras" << endl;		
	} ENDM
    
    return 0;
}

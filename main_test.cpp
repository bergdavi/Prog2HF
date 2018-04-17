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
    


    TEST(Test1, emptyStr) {
      Shape* s = new Square(Vector2(0,0), Vector2(1,1));
      EXPECT_DOUBLE_EQ(4.0, s->getArea()) << "Nem jo a terulet" << endl;
      EXPECT_DOUBLE_EQ(8.0, s->getCircumference()) << "Nem jo a Kerulet" << endl;
      delete s;

    } ENDM
	
	TEST(Test2, emptyStr) {
      Shape* s = new Polygon(Vector2(0,0), Vector2(1,1), 4);
      EXPECT_DOUBLE_EQ(4.0, s->getArea()) << "Nem jo a terulet" << endl;
      EXPECT_DOUBLE_EQ(8.0, s->getCircumference()) << "Nem jo a Kerulet" << endl;
      delete s;

    } ENDM






    cout << "done" << endl;
    return 0;
}

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <math.h>
#include "Vector2.h"




class Shape {
  protected:
    Vector2 center;
    Vector2 point;
    double area;
    double circumference;
  public:
    Shape();
    Shape(Vector2 c, Vector2 point);
    virtual ~Shape();

    double getArea();
    double getCircumference();

    virtual bool inCircle(Vector2 center, double r) = 0;
    virtual bool contains(Vector2 p) = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void draw(std::ostream& os, int shift, int s, const char* color = "black") const = 0;
    friend std::ostream& operator<< (std::ostream& os, const Shape& s);
    friend std::istream& operator>> (std::istream& is, Shape*& s);
};







class ShapeList {

    struct ShapeNode {
        Shape* data;
        ShapeNode* next;
        ShapeNode* prev;

        ShapeNode(Shape* data, ShapeNode* next, ShapeNode* prev);
        ~ShapeNode();
    };

    size_t length;
    ShapeNode* firstNode;
    ShapeNode* lastNode;

  public:
    ShapeList();
    ShapeList(Shape* s);
    ~ShapeList();

    ShapeNode* nodeIter;
    Shape* iter;

    Shape* first();
    Shape* last();
    Shape* next();
    Shape* prev();
    void add(Shape* s);

    int getLength();



};



#endif // SHAPE_H

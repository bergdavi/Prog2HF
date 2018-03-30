#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"

ShapeList::ShapeNode::ShapeNode(Shape* data, ShapeNode* next, ShapeNode* prev):data(data), next(next), prev(prev) {}

ShapeList::ShapeNode::~ShapeNode() {
    delete data;
}


ShapeList::ShapeList():length(0), firstNode(NULL), lastNode(NULL), iter(NULL) {}

ShapeList::ShapeList(Shape *s):length(1) {
    firstNode = new ShapeNode(s, NULL, NULL);
    lastNode = firstNode;
    nodeIter = firstNode;
    iter = nodeIter->data;
}

ShapeList::~ShapeList() {
    ShapeNode* temp = firstNode;
    for(ShapeNode* p = firstNode->next; p != NULL; p=p->next) {
        delete temp;
        temp = p;
    }
    delete temp;
}

Shape* ShapeList::first() {
    nodeIter = firstNode;
    iter = nodeIter->data;
    return iter;
}

Shape* ShapeList::last() {
    nodeIter = lastNode;
    iter = nodeIter->data;
    return iter;
}

Shape* ShapeList::next() {
    if(nodeIter == lastNode) {
        return NULL;
    }
    nodeIter = nodeIter->next;
    iter = nodeIter->data;
    return iter;
}

Shape* ShapeList::prev() {
    if(nodeIter == firstNode) {
        return NULL;
    }
    nodeIter = nodeIter->prev;
    iter = nodeIter->data;
    return iter;
}

void ShapeList::add(Shape* s) {
    if(length == 0) {
        lastNode = new ShapeNode(s, NULL, NULL);
        length = 1;
        firstNode = lastNode;
        nodeIter = firstNode;
        iter = nodeIter->data;
    } else {
        lastNode->next = new ShapeNode(s, NULL, lastNode);
        length++;
        lastNode = lastNode->next;
        lastNode->next = NULL;
    }
}

int ShapeList::getLength() {
    return length;
}

Shape::Shape():center(Vector2(0,0)), point(Vector2(0,0)), area(0), circumference(0) {}
Shape::Shape(Vector2 center, Vector2 point):center(center), point(point) {}


Shape::~Shape() {}

double Shape::getArea() {
    return area;
}

double Shape::getCircumference() {
    return circumference;
}

std::ostream& operator<< (std::ostream& os, const Shape& s) {
    s.print(os);
    return os;
}

std::istream& operator>> (std::istream& is, Shape*& s) {
    std::string type;
    Vector2 center;
    Vector2 point;
    is >> type >> center >> point;
    if(type == "square") {
        s = new Square(center, point);
    }
    else if(type == "triangle") {
        s = new Triangle(center, point);
    }
    else if(type == "circle") {
        s = new Circle(center, point);
    }
    else if(type == "polygon") {
        int sides;
        is >> sides;
        s = new Polygon(center, point, sides);
    }
    return is;
}

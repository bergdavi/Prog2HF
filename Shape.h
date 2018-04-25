/**
 *  \file Shape.h
 *  Shape, ShapeList, ShapeNode oszt�lyok deklar�ci�ja
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <math.h>
#include <stdexcept>
#include "Vector2.h"



/// Shape oszt�ly
/// Szab�lyos s�kidomot t�rol
class Shape {
  protected:
    Vector2 center;         ///< S�kidom k�z�ppontja
    Vector2 point;          ///< S�kidom egy cs�csa
    double area;            ///< S�kidom ter�lete
    double circumference;   ///< S�kidom ker�lete
  public:
    Shape();
    Shape(Vector2 c, Vector2 point);
    virtual ~Shape();

    /// Area getter
    /// @return a s�kidom ter�lete
    double getArea();

    /// Circumference getter
    /// @return a sk�idom ker�lete
    double getCircumference();

    /// S�kidom benne van-e egy k�rben
    /// @param c - a k�r k�z�ppontja
    /// @param r - a k�r sugara
    /// @return benne van-e a k�rben
    virtual bool inCircle(Vector2 center, double r) = 0;

    /// S�kidom tartalmaz-e egy pontot
    /// @param p - a k�rd�ses pont
    /// @return tartalmazza-e a pontot
    virtual bool contains(Vector2 p) = 0;

    /// S�kidom ki�r�sa
    /// @param os - ostream objektum, amire ki�runk
    virtual void print(std::ostream& os) const = 0;

    /// S�kidom rajzol�sa SVG form�tumban
    /// @param os - ostream objektum, amire rajzolunk
    /// @param shift - eltol�s
    /// @param s - nagy�t�s
    /// @param color - sz�n
    virtual void draw(std::ostream& os, int shift, int s, const char* color = "black") const = 0;

    /// << operator
    /// @param os - ostream objektum, amire ki�runk
    /// @param s - amit ki�runk
    friend std::ostream& operator<< (std::ostream& os, const Shape& s);

    /// >> operator
    /// @param is - istream objektum, amir�l beolvasunk
    /// @param s - ahova beolvasunk
    friend std::istream& operator>> (std::istream& is, Shape*& s);

};






/// ShapeList oszt�ly
/// Dupl�n l�ncolt lista, amiben s�kidomokat lehet t�rolni
class ShapeList {
    /// ShapeNode oszt�ly
    /// ShapeList oszt�ly egy eleme
    struct ShapeNode {
        Shape* data;        ///< Mutat� a t�rolt s�kidomra
        ShapeNode* next;    ///< Mutat� a lista k�vetkez� elem�re
        ShapeNode* prev;    ///< Mutat� a lista el�z� elem�re

        ShapeNode(Shape* data, ShapeNode* next, ShapeNode* prev);
        ~ShapeNode();
    };

    size_t length;          ///< A lista m�rete
    ShapeNode* firstNode;   ///< A lista els� eleme
    ShapeNode* lastNode;    ///< A lista utols� eleme

  public:
    ShapeList();
    ShapeList(Shape* s);
    ~ShapeList();

    ShapeNode* nodeIter;    ///< Lista elem�re mutat� iter�tor
    Shape* iter;            ///< Lista adattagj�ra mutat� iter�tor

    /// Iter�tor mozgat�sa az els� elemre
    /// @return mutat� a lista els� elem�re
    Shape* first();

    /// Iter�tor mozgat�sa az utols� elemre
    /// @return mutat� a lista utols� elem�re
    Shape* last();

    /// Iter�tor mozgat�sa a k�vetkez� elemre
    /// @return mutat� a lista k�vetkez� elem�re
    Shape* next();

    /// Iter�tor mozgat�sa az el�z� elemre
    /// @return mutat� a lista el�z� elem�re
    Shape* prev();

    /// A lista tetsz�leges index� elem�nek lek�r�se
    /// @param idx - az elem indexe
    /// @return mutat� a lista megfelel� elem�re
    Shape* get(size_t idx);

    /// �j elem hozz�ad�sa a list�hoz
    /// @param s - hozz�adand� elem
    void add(Shape* s);

    /// Length getter
    /// @return a lista hossza
    int getLength();



};



#endif // SHAPE_H

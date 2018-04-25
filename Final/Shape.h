/**
 *  \file Shape.h
 *  Shape, ShapeList, ShapeNode osztályok deklarációja
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <math.h>
#include <stdexcept>
#include "Vector2.h"



/// Shape osztály
/// Szabályos síkidomot tárol
class Shape {
  protected:
    Vector2 center;         ///< Síkidom középpontja
    Vector2 point;          ///< Síkidom egy csúcsa
    double area;            ///< Síkidom területe
    double circumference;   ///< Síkidom kerülete
  public:
    Shape();
    Shape(Vector2 c, Vector2 point);
    virtual ~Shape();

    /// Area getter
    /// @return a síkidom területe
    double getArea();

    /// Circumference getter
    /// @return a skíidom kerülete
    double getCircumference();

    /// Síkidom benne van-e egy körben
    /// @param c - a kör középpontja
    /// @param r - a kör sugara
    /// @return benne van-e a körben
    virtual bool inCircle(Vector2 center, double r) = 0;

    /// Síkidom tartalmaz-e egy pontot
    /// @param p - a kérdéses pont
    /// @return tartalmazza-e a pontot
    virtual bool contains(Vector2 p) = 0;

    /// Síkidom kiírása
    /// @param os - ostream objektum, amire kiírunk
    virtual void print(std::ostream& os) const = 0;

    /// Síkidom rajzolása SVG formátumban
    /// @param os - ostream objektum, amire rajzolunk
    /// @param shift - eltolás
    /// @param s - nagyítás
    /// @param color - szín
    virtual void draw(std::ostream& os, int shift, int s, const char* color = "black") const = 0;

    /// << operator
    /// @param os - ostream objektum, amire kiírunk
    /// @param s - amit kiírunk
    friend std::ostream& operator<< (std::ostream& os, const Shape& s);

    /// >> operator
    /// @param is - istream objektum, amiröl beolvasunk
    /// @param s - ahova beolvasunk
    friend std::istream& operator>> (std::istream& is, Shape*& s);

};






/// ShapeList osztály
/// Duplán láncolt lista, amiben síkidomokat lehet tárolni
class ShapeList {
    /// ShapeNode osztály
    /// ShapeList osztály egy eleme
    struct ShapeNode {
        Shape* data;        ///< Mutató a tárolt síkidomra
        ShapeNode* next;    ///< Mutató a lista következö elemére
        ShapeNode* prev;    ///< Mutató a lista elözö elemére

        ShapeNode(Shape* data, ShapeNode* next, ShapeNode* prev);
        ~ShapeNode();
    };

    size_t length;          ///< A lista mérete
    ShapeNode* firstNode;   ///< A lista elsö eleme
    ShapeNode* lastNode;    ///< A lista utolsó eleme

  public:
    ShapeList();
    ShapeList(Shape* s);
    ~ShapeList();

    ShapeNode* nodeIter;    ///< Lista elemére mutató iterátor
    Shape* iter;            ///< Lista adattagjára mutató iterátor

    /// Iterátor mozgatása az elsö elemre
    /// @return mutató a lista elsö elemére
    Shape* first();

    /// Iterátor mozgatása az utolsó elemre
    /// @return mutató a lista utolsó elemére
    Shape* last();

    /// Iterátor mozgatása a következö elemre
    /// @return mutató a lista következö elemére
    Shape* next();

    /// Iterátor mozgatása az elözö elemre
    /// @return mutató a lista elözö elemére
    Shape* prev();

    /// A lista tetszöleges indexü elemének lekérése
    /// @param idx - az elem indexe
    /// @return mutató a lista megfelelö elemére
    Shape* get(size_t idx);

    /// Új elem hozzáadása a listához
    /// @param s - hozzáadandó elem
    void add(Shape* s);

    /// Length getter
    /// @return a lista hossza
    int getLength();



};



#endif // SHAPE_H

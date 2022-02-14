#ifndef SHAPES_H
#define SHAPES_H
#include <vector>
#include <string>
#include <iostream>
#include "Exc.h"

using namespace std;

struct coord {
		double x, y;
		coord(double X, double Y){
			x = X;
			y = Y;
		}
	};
class Shape
{
public: 
	Shape(const std::vector<coord>& newCoords);
	virtual ~Shape(){};
	virtual double Area() =0;
	virtual string toString();
	void Draw();
	void Move(double x, double y);
	vector<coord> getCoords();
	coord getPosition();

protected:
	string name;
	
	vector<coord> coords;
};
class Rectangle : public Shape
{
public:
	double a, b;
	virtual double Area();
	Rectangle(const vector<coord>& newCoords) : Shape(newCoords) {
		a = coords[1].x - coords[0].x;
		b = coords[2].y - coords[0].y;
		name = "Rectangle";
	}
	virtual ~Rectangle(){};
};
class Square : public Rectangle
{
public:
	virtual double Area();
	Square(const vector<coord>& newCoords) : Rectangle(newCoords) {
		name = "Square";
	}
};
class Oval : public Rectangle {
public:
	virtual double Area();
	Oval(const vector<coord>& newCoords) : Rectangle(newCoords) {
		name = "Oval";
	}
	virtual ~Oval(){};
};
class Circle : public Oval {
public:
	Circle(const vector<coord>& newCoords) : Oval(newCoords) {
		name = "Circle";
	}
	virtual double Area();
};

class Triangle : public Shape
{	
public:
	virtual double Area();
	Triangle(const vector<coord>& newCoords) : Shape(newCoords) {
		name = "Triangle";
	}
};
template <typename T>
double Volume(double h, T& s){
	if (h > 0){
		return (h * s.Area());
	}
	else throw Exception(1, "failed to calculate volume");
}
#endif
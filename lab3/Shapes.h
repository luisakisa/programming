#ifndef SHAPES_H
#define SHAPES_H
#include <vector>
#include <string>

using namespace std;
class Shape
{
protected:
	string name;
	struct coord {
		double x, y;
		coord(double X, double Y){
			x = X;
			y = Y;
		}
	};
	vector<coord> coords;
public: 
	Shape();
	virtual ~Shape(){};
	virtual double Area() =0;
	virtual string toString();
	void Draw();
	void Move(double x, double y);
};
class Rectangle : public Shape
{
public:
	double a, b;
	virtual double Area();
	Rectangle() {
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
	Square() {
		name = "Square";
	}
};
class Oval : public Rectangle {
public:
	virtual double Area();
	Oval() {
		name = "Oval";
	}
	virtual ~Oval(){};
};
class Circle : public Oval {
public:
	Circle() {
		name = "Circle";
	}
	virtual double Area();
};

class Triangle : public Shape
{	
public:
	virtual double Area();
	Triangle() {
		name = "Triangle";
	}
};
class Cylinder{
	public:
	double h;
	double receiveH();
	double Volume(Shape*);
	Cylinder(){
		receiveH();
	};
};

#endif
#include <iostream>
#include <string>
#include "Shapes.h"
#define _USE_MATH_DEFINES
#include <math.h>

Shape::Shape(const std::vector<coord>& newCoords) {
	coords = newCoords;
}
void Shape::Move(double x, double y) {
	for (unsigned int i = 0; i < coords.size(); i++) {
		coords[i].x += x;
	}
	for (unsigned int i = 0; i < coords.size(); i++) {
		coords[i].y += y;
	}
}

string Shape::toString() {
	string a;
	a = "Name: " + name + "; ";
	for (unsigned int i = 0; i < coords.size(); i++) {
		a += "Coords: x = " + to_string(coords[i].x) + ", y = " + to_string(coords[i].y) + "; ";
	}
	return a;
}
void Shape::Draw() {
	return;
}

vector<coord> Shape::getCoords() {
	return coords;
}

coord Shape::getPosition() {
	return coords[0];
}

double Rectangle::Area() {
	return a * b;
}
double Square::Area() {
	return a * a;
}

double Oval::Area() {

	return  M_PI * a*b;
}
double Circle::Area() {

	return  M_PI * a*a;
}

double Triangle::Area() {
	return 0.5 * abs((coords[1].x - coords[0].x)*(coords[2].y - coords[0].y) 
		- (coords[2].x - coords[0].x)*(coords[1].y - coords[0].y));
}


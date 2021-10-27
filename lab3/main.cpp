#include <iostream>
#include <string>

#include "Shapes.h"

using namespace std;

int main()
{
	double x, y;
	unsigned int i;
	Rectangle rectangle;
	Triangle triangle;
	Square square;
	Oval oval;
	Circle circle;
	Shape* shapes[] = { &rectangle, &triangle, &square, &oval, &circle };
	Cylinder c;
	for (i = 0; i < 5; i++) {
		cout << i+1<< ". Coordinates: " << shapes[i]->toString() << endl << "	Area: "
		<< shapes[i]->Area() << endl << "	Volume:" << c.Volume(shapes[i]) << endl << endl;
	}
	cout << "what shape you want to move: "; cin >> i;
	while(i>4||i<0){
		cout<<"error"<<endl;
		cout << "what shape you want to move: "; cin >>i;
		
	}
	
	cout << "how much to move(x , y): "; cin >> x >> y;
	shapes[i]->Move(x, y);
	for (i = 0; i < 5; i++) {
		cout << i+1<< ". " << shapes[i]->toString() << endl;
	}
	for (i = 0; i < 5; i++) {
		delete shapes[i];
	}
	return 0;
}
#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Shapes.h"

using namespace std;

class EllipseShape : public sf::Shape
{
public :

    explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0.f, 0.f)) :
    m_radius(radius)
    {
        update();
	}
    void setRadius(const sf::Vector2f& radius)
    {
        m_radius = radius;
        update();
    }

    const sf::Vector2f& getRadius() const
    {
        return m_radius;
    }

    virtual std::size_t getPointCount() const
    {
        return 30; // fixed, but could be an attribute of the class if needed
    }

    virtual sf::Vector2f getPoint(std::size_t index) const
    {
        static const float pi = 3.141592654f;

        float angle = index * 2 * pi / getPointCount() - pi / 2;
        float x = std::cos(angle) * m_radius.x;
        float y = std::sin(angle) * m_radius.y;

        return sf::Vector2f(m_radius.x + x, m_radius.y + y);
    }

private :

    sf::Vector2f m_radius;
};

int main()
{
	double x, y;
	unsigned int i;
	Rectangle rectangle({{10, 10}, {20, 10}, {10, 40}, {20, 40}});
	Triangle triangle({{30, 10}, {40, 10}, {30, 40}});
	Square square({{60, 10}, {80, 10}, {60, 30}, {80, 30}});
	Oval oval({{10, 70}, {20, 70}, {10, 100}, {20, 100}});
	Circle circle({{40, 70}, {60, 70}, {40, 90}, {60, 90}});
	double h;
	Shape* shapes[] = { &rectangle, &triangle, &square, &oval, &circle };
	cout<< "Input h of cylinder: "; std::cin>> h;
	 try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
	{ 
					for (i = 0; i < 5; i++) {
						cout << i+1<< ". Coordinates: " << shapes[i]->toString() << endl << "	Area: "
						<< shapes[i]->Area() << endl << endl;
					}
					cout<< "Volume:" << endl << "	rectangle " << Volume<Rectangle>(h, rectangle) << endl;

					cout<< "	triangle " << Volume<Triangle>(h, triangle) << endl;
					cout<< "	square " << Volume<Square>(h, square) << endl;
					cout<< "	oval " << Volume<Oval>(h, oval) << endl;
					cout<< "	circle " << Volume<Circle>(h, circle) << endl;
	}
catch (Exception& error)
		{
			error.show();
			cout << "Try again..." << endl << endl;
		}
	sf::RenderWindow window(sf::VideoMode(500, 300), "lab 3");

	sf::RectangleShape rectangleShape;
	rectangleShape.setFillColor(sf::Color::Yellow);

	sf::ConvexShape triangleShape;
	// resize it to 5 points
	triangleShape.setPointCount(3);
	triangleShape.setFillColor(sf::Color::White);
	triangleShape.setPosition(triangle.getPosition().x, triangle.getPosition().y);

	sf::RectangleShape squareShape;
	squareShape.setFillColor(sf::Color::Cyan);
	squareShape.setPosition(square.getPosition().x, square.getPosition().y);

    sf::CircleShape circleShape;
	circleShape.setFillColor(sf::Color::Green);
	circleShape.setPosition(circle.getPosition().x, circle.getPosition().y);
	EllipseShape ovalShape;
	ovalShape.setFillColor(sf::Color::Red);
	ovalShape.setPosition(oval.getPosition().x, oval.getPosition().y);
	
	rectangleShape.setSize(sf::Vector2f(rectangle.a, rectangle.b));
	rectangleShape.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);

	vector<coord> triangleCoords = triangle.getCoords();
	for(int i = 0; i < triangleCoords.size(); i++) {
		triangleShape.setPoint(i, sf::Vector2f(triangleCoords[i].x, triangleCoords[i].y));
	}

	squareShape.setSize(sf::Vector2f(square.a, square.b));

	circleShape.setRadius(circle.a);

	ovalShape.setRadius(sf::Vector2f(oval.a, oval.b));
 

	
while (i)
	{
		cout << "what shape you want to move: "; cin >> i;
		while(i>5||i<1){
			cout << "no such number "; cin >>i;
		}
		cout << "how much to move(x , y): "; cin >> x >> y;
		shapes[i-1]->Move(x, y);
		for (int m = 0; m < 5; m++) {
			cout << m+1<< ". " << shapes[m]->toString() << endl;
		}
		switch (i)
		{
		case 1:
		{
			rectangleShape.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);
			break;
		}
		case 2:
		{
			triangleShape.setPosition(triangle.getPosition().x, triangle.getPosition().y);
			break;
		}
		case 5:
		{
				circleShape.setPosition(circle.getPosition().x, circle.getPosition().y);
			break;
		}
		case 4:
		{
			ovalShape.setPosition(oval.getPosition().x, oval.getPosition().y);
			break;
		}
		case 3:
		{
			squareShape.setPosition(square.getPosition().x, square.getPosition().y);
			break;
		}
		
		}
		system("cls");
			sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}

				window.clear();
				window.draw(circleShape);
				window.draw(triangleShape);
				window.draw(rectangleShape);
				window.draw(squareShape);
				window.draw(ovalShape);
				window.display();
	}
	return 0;
}
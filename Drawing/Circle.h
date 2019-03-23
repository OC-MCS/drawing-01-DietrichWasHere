#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;



class Circle : public DrawingShape
{
private:
	CircleShape stamp;
public:
	// constructor; used in other classes constructors;
	// create circle from location, color
	Circle(Vector2f nPos, Color nColor) : DrawingShape(CIRCLE)
	{
		const int RADIUS = 20;
		stamp.setPosition(nPos);
		stamp.setRadius(RADIUS);
		stamp.setOutlineThickness(2);
		stamp.setOutlineColor(nColor);
		stamp.setFillColor(Color::Transparent);
	}
	// draw the circle
	virtual void draw(RenderWindow& win)
	{
		win.draw(stamp);
	}
	// return a shapedata full of the circle's info
	virtual ShapeData getFileRecord()
	{
		ShapeData data;
		data.sdShape = getShape();
		data.pos = stamp.getPosition();
		data.color = stamp.getOutlineColor().toInteger();
		return data;
	}
};
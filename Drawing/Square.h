#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;



class Square : public DrawingShape
{
private:
	RectangleShape stamp; // square to draw
public:
	// constructor; used in other classes constructors;
	// create the square from location, color
	Square(Vector2f nPos, Color nColor) : DrawingShape(SQUARE)
	{
		const int SIZE = 40;
		stamp.setPosition(nPos);
		stamp.setOutlineThickness(2);
		stamp.setSize(Vector2f(SIZE, SIZE));
		stamp.setOutlineColor(nColor);
		stamp.setFillColor(Color::Transparent);
	}
	// draw the square in the window given
	virtual void draw(RenderWindow& win)
	{
		win.draw(stamp);
	}
	// return a Shapedata full of the square's info
	virtual ShapeData getFileRecord()
	{
		ShapeData data;
		data.sdShape = getShape();
		data.pos = stamp.getPosition();
		data.color = stamp.getOutlineColor().toInteger();
		return data;
	}
};
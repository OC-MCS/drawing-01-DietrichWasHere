#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;



class Square : public DrawingShape
{
private:
	RectangleShape stamp;
public:
	// constructor; used in other classes constructors;

	Square(Vector2f nPos, Color nColor) : DrawingShape(CIRCLE)
	{
		const int SIZE = 40;
		stamp.setPosition(nPos);
		stamp.setOutlineThickness(2);
		stamp.setSize(Vector2f(SIZE, SIZE));
		stamp.setOutlineColor(nColor);
		stamp.setFillColor(Color::Transparent);
	}
	virtual void draw(RenderWindow& win)
	{
		win.draw(stamp);
	}
	virtual ShapeData getFileRecord()
	{
		ShapeData data;
		data.sdShape = getShape();
		data.pos = stamp.getPosition();
		data.color = stamp.getOutlineColor().toInteger();
		return data;
	}
};
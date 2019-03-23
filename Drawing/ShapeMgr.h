#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape *> shapeList;
public:
	ShapeMgr()
	{

	}
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		DrawingShape* nShape = nullptr;
		if (whichShape == CIRCLE)
		{
			nShape = new Circle(pos, color);
		}
		else
		{
			nShape = new Square(pos, color);
		}
		shapeList.push_back(nShape);
	}
	void addShape(ShapeData sd)
	{
		DrawingShape* nShape = nullptr;
		if (sd.sdShape == CIRCLE)
		{
			nShape = new Circle(sd.pos, Color(sd.color));
		}
		else if (sd.sdShape == SQUARE)
		{
			nShape = new Square(sd.pos, Color(sd.color));
		}
		shapeList.push_back(nShape);
	}
	void loadFile(iostream &strObj)
	{

	}
	void saveFile(iostream &strObj)
	{

	}
	const vector<DrawingShape *>* getList()
	{
		return &shapeList;
	}
};

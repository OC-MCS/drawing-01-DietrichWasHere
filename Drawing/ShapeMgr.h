#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

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
			
		}
		else
		{

		}
		shapeList.push_back(nShape);
	}
	void addShape(ShapeData sd)
	{
		DrawingShape* nShape = nullptr;
		if (sd.sdShape == CIRCLE)
		{

		}
		else
		{

		}
		shapeList.push_back(nShape);
	}
	void loadFile(iostream &strObj)
	{

	}
	void saveFile(iostream &strObj)
	{

	}
};

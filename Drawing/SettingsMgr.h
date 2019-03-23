#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shape.h"
using namespace std;
using namespace sf;


// Shape Enum moved to shape object file
// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color curColor; // hold color for all new shapes
	ShapeEnum curShape; // hold shape for new shapes
public:
	// constructor - for deafault values, using direct color, shape inputs
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		curColor = startingColor;
		curShape = startingShape;
	}
	void loadFromFile(iostream &strObj);
	void saveToFile(iostream &strObj);
	// return current color
	Color getCurColor()
	{
		return curColor;
	}
	// return current shape
	ShapeEnum getCurShape()
	{
		return curShape;
	}
	// set color
	void setCurColor(Color nColor)
	{
		curColor = nColor;
	}
	// set shape
	void setCurShape(ShapeEnum nShape)
	{
		curShape = nShape;
	}

};

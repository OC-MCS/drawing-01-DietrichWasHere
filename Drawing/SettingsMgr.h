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
	Color curColor;
	ShapeEnum curShape;
public:
	// constructor - for deafault
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

	ShapeEnum getCurShape()
	{
		return curShape;
	}
	void setCurColor(Color nColor)
	{
		curColor = nColor;
	}

	void setCurShape(ShapeEnum nShape)
	{
		curShape = nShape;
	}

};

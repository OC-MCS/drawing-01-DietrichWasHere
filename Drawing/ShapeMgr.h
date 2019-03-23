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
	vector<DrawingShape *> shapeList; // hold the shapes! yes I tired
public:
	ShapeMgr()
	{
	}
	// add a shape using the 3 needed variables to distinguish in the file
	// position, circle or square, and color (R,B,G)
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		DrawingShape* nShape = nullptr;
		if (whichShape == CIRCLE)
		{
			nShape = new Circle(pos, color); // create a circle
		}
		else
		{
			nShape = new Square(pos, color); // create a square
		}
		shapeList.push_back(nShape); // add to vector / list
	}
	// same as above, but from a ShapeData struct, which contains all the necessary info; can be derived from file
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
	// load shapes from file, recieved
	void loadFile(iostream &file)
	{
		ShapeData nShape;
		while (file.read(reinterpret_cast<char *>
			(&nShape), sizeof(nShape)))
		{
			addShape(nShape);
		}
	}
	// save to file, which is passed by ref
	void saveFile(iostream &file)
	{
		ShapeData shapeOut;
		for (int i = 0; i < (shapeList.size()); i++)
		{
			shapeOut = shapeList[i]->getFileRecord();
			file.write(reinterpret_cast<char *>(&shapeOut), sizeof(shapeOut));
		}
	}
	const vector<DrawingShape *>* getList()
	{
		return &shapeList;
	}
};

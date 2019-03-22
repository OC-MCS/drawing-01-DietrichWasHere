#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
// enumeratred data type to distinguish between struct for square and struct for circle
enum ShapeEnum { CIRCLE, SQUARE };

// used for file storage of Drawing Shape inheriting classes
struct ShapeData
{
	// shape type
	ShapeEnum sdShape = CIRCLE;
	// position of shape object
	Vector2f pos;
	// color of shape object
	unsigned int color;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	ShapeData shapeInfo;
public:
	// constructor; used in other classes constructors;
	DrawingShape(ShapeEnum nShape, Vector2f nPos, unsigned int nColor)
	{
		shapeInfo.sdShape = nShape;
		shapeInfo.pos = nPos;
		shapeInfo.color = nColor;
	}
	virtual void draw(RenderWindow& win)
	{

	}
	virtual ShapeData getFileRecord()
	{
		return shapeInfo;
	}
};

// add Circle, Square classes below. These are derived from DrawingShape




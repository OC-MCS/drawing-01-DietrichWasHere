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
	ShapeEnum dsShape; // enable distinguishing between derived classes when loaded from file
public:
	// constructor; used in other classes constructors;
	// initialize enumerated shape value
	DrawingShape(ShapeEnum nShape)
	{
		dsShape = nShape;
	}
	// allow access to enumerated shape's value, even thoug its private
	ShapeEnum getShape()
	{
		return dsShape;
	}
	// virtual functions, so that these functions can be used by inheriting classes at same location
	virtual void draw(RenderWindow& win) =0;
	virtual ShapeData getFileRecord() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape
// o. ohhhhhhhhh....... whoops. see other files



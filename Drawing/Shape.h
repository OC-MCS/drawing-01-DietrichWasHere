#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
// enumeratred data type to distinguish between struct for square and struct for circle
enum  shapeType {CIRCLE, SQUARE};

// used for file storage of Drawing Shape ingeriting classes
struct ShapeData
{
	shapeType sdShape = CIRCLE;

	int color;

};



// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{

};

// add Circle, Square classes below. These are derived from DrawingShape




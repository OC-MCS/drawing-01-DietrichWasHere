#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ShapeMgr.h"
using namespace std;
using namespace sf;


// finish this code; add functions, data as needed
const int SHAPE_SIZE = 40;
// object size, used to keep objects in margins

class DrawingUI
{
private:
	Vector2f lBounds; // Upper and left bounds, hopefully the window handles the other bounds well enough
	Vector2f window; // window size, to ensure objects stay in line
	int margin; // set bounds of shape placement
public:
	// constructor gets values to determine margins
	DrawingUI(Vector2f p, Vector2f w, int m)
	{
		lBounds = p;
		window = w;
		margin = m;
	}
	// param: win, shape manager (for list)
	// display list of shapes in window
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		const vector<DrawingShape *>* shapeList = mgr->getList();
		for (int i = 0; i < (shapeList->size()); i++)
		{
			(*shapeList)[i]->draw(win);
		}
	}
	// check if mouse is in bounds using mouse position
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inBounds = false;
		if ((mousePos.x > (lBounds.x + margin)) && (mousePos.y > (lBounds.y + margin)) &&
			(mousePos.x < (window.x - (margin + SHAPE_SIZE))) && (mousePos.y < window.y - (margin + SHAPE_SIZE)))
		{
			inBounds = true;
		}
		return inBounds; // just to make it compile
	}

};


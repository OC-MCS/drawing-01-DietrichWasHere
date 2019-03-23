#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	Vector2f bounds;

public:
	DrawingUI(Vector2f p)
	{
		bounds = p;
	}
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		const vector<DrawingShape *>* shapeList = mgr->getList();
		for (int i = 0; i < (shapeList->size()); i++)
		{
			(*shapeList)[i]->draw(win);
		}
	}
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inBounds = false;
		if ((mousePos.x > bounds.x) && (mousePos.y > bounds.y))
		{
			inBounds = true;
		}
		return inBounds; // just to make it compile
	}

};


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SettingsMgr.h"
using namespace std;
using namespace sf;


// finish this code; add functions, data as needed



// kill program when font does not load
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}


class SettingsUI
{
private:
	SettingsMgr *mgr; // ptr to ref settings manager, which holds settings
	Font font; // for loading font
	Text colorTxt; // text to indicate color opt
	CircleShape redBtn; // select for red
	CircleShape blueBtn; // select for blue
	CircleShape greenBtn; // select for green
	Text shapeTxt; // text above shape options
	CircleShape circleBtn; // select for circles
	RectangleShape sqrBtn; // select for squares
	RectangleShape uiBackground; // distinguish between canvas and option panel
	
public:
	// construct using presets and inputed ptr to settingsMgr
	SettingsUI(SettingsMgr *nMgr)
	{	
		const int UI_WIDTH = 200; // width of ui panel
		const int UI_HEIGHT = 600; // hieght of ui panel
		const int RADIUS = 20;	// button size
		mgr = nMgr;
		uiBackground.setPosition(Vector2f(0, 0));
		uiBackground.setOutlineColor(Color::Black);
		uiBackground.setOutlineThickness(2);
		uiBackground.setSize(Vector2f(UI_WIDTH, UI_HEIGHT));
		uiBackground.setFillColor(Color::White);
		
		// try loading font
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		colorTxt.setFont(font);
		colorTxt.setFillColor(Color::Black);
		colorTxt.setCharacterSize(25);
		colorTxt.setString("Selected Color");
		colorTxt.setPosition(UI_WIDTH / 20, (UI_HEIGHT * 1) / 10);
		
		redBtn.setPosition(Vector2f((UI_WIDTH - RADIUS) / 2, (UI_HEIGHT * 2) / 10));
		redBtn.setRadius(RADIUS);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		
		blueBtn.setPosition(Vector2f((UI_WIDTH - RADIUS) / 2, (UI_HEIGHT * 3) / 10));
		blueBtn.setRadius(RADIUS);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		
		greenBtn.setPosition(Vector2f((UI_WIDTH - RADIUS) / 2, (UI_HEIGHT * 4) / 10));
		greenBtn.setRadius(RADIUS);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
	
		shapeTxt.setFont(font);
		shapeTxt.setFillColor(Color::Black);
		shapeTxt.setCharacterSize(25);
		shapeTxt.setString("Selected Shape");
		shapeTxt.setPosition(UI_WIDTH / 20, (UI_HEIGHT * 6) / 10);

		circleBtn.setPosition(Vector2f((UI_WIDTH - RADIUS) / 2, (UI_HEIGHT * 7) / 10));
		circleBtn.setRadius(RADIUS);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::Black);

		sqrBtn.setPosition(Vector2f((UI_WIDTH - RADIUS) / 2, (UI_HEIGHT * 8) / 10));
		sqrBtn.setOutlineThickness(2);
		sqrBtn.setSize(Vector2f(RADIUS * 2, RADIUS * 2));
		sqrBtn.setOutlineColor(Color:: Black);
	}

	// load presets from mgr
	void loadPresets()
	{
		// load presets
		if (mgr->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (mgr->getCurColor() == Color::Blue)
		{
			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Blue);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (mgr->getCurColor() == Color::Green)
		{
			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
		}
		// load presets
		if (mgr->getCurShape() == ShapeEnum::CIRCLE)
		{
			circleBtn.setFillColor(Color::Black);
			sqrBtn.setFillColor(Color::Transparent);
		}
		else if (mgr->getCurShape() == ShapeEnum::SQUARE)
		{
			circleBtn.setFillColor(Color::Transparent);
			sqrBtn.setFillColor(Color::Black);
		}
	}

	// use mouse position to determine ui action
	void handleMouseUp(Vector2f mouse)
	{
		if (redBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setCurColor(Color::Red);
			redBtn.setFillColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (blueBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setCurColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Blue);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setCurColor(Color::Green);
			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
		}
		else if (circleBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setCurShape(ShapeEnum::CIRCLE);
			circleBtn.setFillColor(Color::Black);
			sqrBtn.setFillColor(Color::Transparent);
		}
		else if (sqrBtn.getGlobalBounds().contains(mouse))
		{
			mgr->setCurShape(ShapeEnum::SQUARE);
			circleBtn.setFillColor(Color::Transparent);
			sqrBtn.setFillColor(Color::Black);
		}
	}
	// use win to draw all items
	void draw(RenderWindow& win)
	{
		win.draw(uiBackground);
		win.draw(colorTxt);
		win.draw(redBtn);
		win.draw(blueBtn);
		win.draw(greenBtn);
		win.draw(shapeTxt);
		win.draw(circleBtn);
		win.draw(sqrBtn);
	}
	// hmmm... not sure the destructor is working
	// fixed if you close out of the text window
	// Fixed
	~SettingsUI()
	{
	}
};

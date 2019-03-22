#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

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
	SettingsMgr *mgr;
	Font font;
	Text colorTxt;
	CircleShape redBtn;
	CircleShape blueBtn;
	CircleShape greenBtn;
	Text shapeTxt;
	CircleShape circleBtn;
	RectangleShape sqrBtn;
	RectangleShape uiBackground;
	
public:
	SettingsUI(SettingsMgr *nMgr)
	{
		const int UI_WIDTH = 200;
		const int UI_HEIGHT = 600;
		const int RADIUS = 30;
		
		mgr = nMgr;
		uiBackground.setPosition(Vector2f(UI_WIDTH / 2, UI_HEIGHT / 600));
		uiBackground.setOutlineColor(Color::Black);
		uiBackground.setOutlineThickness(2);
		uiBackground.setSize(Vector2f(UI_WIDTH, UI_HEIGHT));
		uiBackground.setFillColor(Color::White);
		
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		colorTxt.setFont(font);
		colorTxt.setCharacterSize(25);
		colorTxt.setString("Selected Color");
		colorTxt.setPosition(UI_WIDTH / 2, (UI_HEIGHT * 9) / 10);
		
		redBtn.setPosition(Vector2f(UI_WIDTH / 2, (UI_HEIGHT * 8) / 10));
		redBtn.setRadius(RADIUS);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		
		blueBtn.setPosition(Vector2f(UI_WIDTH / 2, (UI_HEIGHT * 7) / 10));
		blueBtn.setRadius(RADIUS);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		
		greenBtn.setPosition(Vector2f(UI_WIDTH / 2, (UI_HEIGHT * 6) / 10));
		greenBtn.setRadius(RADIUS);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);

		if (nMgr->getCurColor == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (nMgr->getCurColor == Color::Blue)
		{
			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Blue);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (nMgr->getCurColor == Color::Green)
		{
			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
		}
		
		shapeTxt.setFont(font);
		shapeTxt.setCharacterSize(25);
		shapeTxt.setString("Selected Shape");
		shapeTxt.setPosition(UI_WIDTH / 2, (UI_HEIGHT * 4) / 10);

		circleBtn.setPosition(Vector2f(UI_WIDTH / 2, (UI_HEIGHT * 3) / 10));
		circleBtn.setRadius(RADIUS);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::Black);

		sqrBtn.setPosition(Vector2f(UI_WIDTH / 2, (UI_HEIGHT * 2) / 10));
		sqrBtn.setOutlineThickness(2);
		sqrBtn.setSize(Vector2f(RADIUS * 2, RADIUS * 2));
		sqrBtn.setOutlineColor(Color::White);

		if (nMgr->getCurShape == ShapeEnum::CIRCLE)
		{
			circleBtn.setFillColor(Color::Black);
			sqrBtn.setFillColor(Color::Transparent);
		}
		else if (nMgr->getCurShape == ShapeEnum::SQUARE)
		{
			circleBtn.setFillColor(Color::Transparent);
			sqrBtn.setFillColor(Color::Black);
		}
	}
	void handleMouseUp(Vector2f mouse)
	{

	}
	void draw(RenderWindow& win)
	{
		//win.draw();
	}
};

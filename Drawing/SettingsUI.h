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
		const int BTN_SIZE = RADIUS * 2;
		
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

		switch (nMgr->getCurColor)
		{
			blueBtn.setFillColor(Color::Transparent);
		}
		switch (nMgr->getCurShape)
		{

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

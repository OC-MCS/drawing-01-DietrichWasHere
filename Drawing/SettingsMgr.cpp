#include "SettingsMgr.h"
#include <iostream>
using namespace std;


void SettingsMgr::loadFromFile(iostream &file)
{
	unsigned int nColor;
	file.read(reinterpret_cast<char *>(&nColor), sizeof(nColor));
	curColor = Color(nColor);
	file.read(reinterpret_cast<char *>(&curShape), sizeof(curShape));
}
void SettingsMgr::saveToFile(iostream &file)
{
	unsigned int colorOut;
	colorOut = curColor.toInteger();
	file.write(reinterpret_cast<char *>(&colorOut), sizeof(colorOut));
	file.write(reinterpret_cast<char *>(&curShape), sizeof(curShape));
}
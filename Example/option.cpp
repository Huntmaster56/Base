#include "option.h"
#include "sfwdraw.h"
#include <iostream>
using namespace sfw;

void Option::init(int a_font)
{
	font = a_font;

}

void Option::play() { timer = 3.f; }

void Option::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Splash Time: %f", timer);
	drawString(font, "Press B to go back", 100, 100, 20, 20);
	setBackgroundColor(BLACK);
}

void Option::step() { timer -= getDeltaTime(); }

APP_STATE Option::next()
{
	if (getKey('B'))
	{
		return ENTER_DEPART;
	}
	return OPTION;
}
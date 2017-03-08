#include "sfwdraw.h"
#include <iostream>
#include "splash.h"
using namespace sfw;

void Splash::init(int a_font)
{
	font = a_font;

}

void Splash::play() { timer = 2.f; }

void Splash::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Splash Time: %f", timer);
//	setBackgroundColor(BLACK);
	drawString(font, "Welcome to Ping Pong", 100, 400, 30, 30);
	drawLine(100, 80, 100 + 300 * (timer / 2.f), 80);
}

void Splash::step() { timer -= getDeltaTime(); }

APP_STATE Splash::next()
{
	if (timer < 0)
	{
		return ENTER_GAMESTATE;
	}
	return SPLASH;
}
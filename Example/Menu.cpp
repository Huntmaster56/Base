#include "Menu.h"
#include "sfwdraw.h"
#include <iostream>
using namespace sfw;

void Menu::init(int a_font)
{
	font = a_font;

}

void Menu::play() { timer = 3.f; }

void Menu::draw()
{
	char buffer[100];
	sprintf_s(buffer, "Splash Time: %f", timer);
	drawString(font, "Welcome play with a friend or if \nyou have non and are lonley play \nagainst your self. \nThe controls are below, durring \nthe game more balls will spawn in \nover time have fun.", 100, 460, 20, 20);
	drawString(font, "Player 1 controls: \n W - up \n S - down", 100, 320, 20, 20);
	drawString(font, "Player 1 controls: \n I - up \n K - down", 100, 240, 20, 20);
	drawString(font, "Press P to play", 100, 150, 20, 20);
	drawString(font, "Press O for options", 100, 100, 20, 20);
	setBackgroundColor(BLACK);
}

void Menu::step() { timer -= getDeltaTime(); }

APP_STATE Menu::next()
{
	if (getKey('O'))
	{
		return ENTER_OPTION;
	}
	if (getKey('P'))
	{
		return ENTER_GAMESTATE;
	}
	return DEPART;
}
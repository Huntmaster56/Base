#include "win.h"
#include "sfwdraw.h"
#include <iostream>

void Win::init(int a_font)
{
	font = a_font;
}

void Win::play() { timer = 3.f; }

void Win::draw()
{
}

void Win::step()
{
}

APP_STATE Win::next()
{
	return APP_STATE();
}

#include "score.h"
#include "sfwdraw.h"
#include <iostream>
#include <cstdio>
using namespace sfw;


void drawScore(unsigned font, int score1, int score2)
{
	char buffer[80] = { 0 };

	sprintf_s(buffer, "%d", score1);
	drawString(font, buffer, 100, 550, 35, 35);
}


void drawWin(unsigned font)
{
	drawString(font, "Game over Player 1 wins", 130, 500, 25, 25);
}


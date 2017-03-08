#include "Depart.h"
#include "splash.h"
#include "sfwdraw.h"
#include "GameState.h"
#include "constdecl.h"
#include "option.h"

/*
	The main function should be used for application state management.
	Currently, only one state is implemented here, you'll need to add additional
	and get them to behave properly.
*/
void main()
{
	sfw::initContext();

	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	GameState gs;

	Splash splash;
	Depart depart;

	depart.init(font);
	splash.init(font);
	gs.init(); 
	APP_STATE state = ENTER_SPLASH;

	while (sfw::stepContext())
	{
		switch (state)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;
		//case ENTER_DEPART:
		//case DEPART:
		//	depart.draw();
		//	state = depart.next();
		//	break;
		case ENTER_GAMESTATE:
			gs.play();
		case GAMESTATE:
			gs.step();
			gs.draw();
			
			state = (APP_STATE)gs.next();
			break;
//		case ENTER_WIN:
//			gs.play();
//		case WIN:

		}
	}

	gs.stop(); // should be called each time the state is transitioned out of

	gs.term(); // called once


	sfw::termContext();

}
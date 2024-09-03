#include "Game.h"

#ifdef RELESE_MODE

int WinMain()
{
	flappy_bird::Game* game = new flappy_bird::Game();
	game->Run();
	delete game;
}

#endif

#ifdef DEBUG_MODE

int main()
{
	flappy_bird::Game* game = new flappy_bird::Game();
	game->Run();
	delete game;
}

#endif
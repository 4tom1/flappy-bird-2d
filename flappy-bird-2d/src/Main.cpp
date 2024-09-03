#include "Game.h"

#include "../resource.h"

int WinMain()
{
	flappy_bird::Game* game = new flappy_bird::Game();
	game->Run();
	delete game;
}
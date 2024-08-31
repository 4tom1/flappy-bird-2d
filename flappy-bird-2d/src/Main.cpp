#include "Game.h"
#include <iostream>

int main()
{
	flappy_bird::Game* game = new flappy_bird::Game();
	game->Run();
	delete game;
}
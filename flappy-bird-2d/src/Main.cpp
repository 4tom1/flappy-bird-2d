#include "Game.h"

int main()
{
	flappy_bird::Game* game = new flappy_bird::Game();
	game->Run();
	delete game;
}
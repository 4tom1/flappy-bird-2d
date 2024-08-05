#include "Game.h"

int main()
{
	flappy_bird_2D::Game* game = new flappy_bird_2D::Game();
	game->Run();
	delete game;
}
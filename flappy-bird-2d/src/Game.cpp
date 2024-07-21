#include <flappy_engine.h>

#include "Game.h"

using namespace flappy_bird_2D;

Game::Game()
{
	flappy_engine::F_engine = flappy_engine::InitEngine();
}

void Game::Run()
{
	while (IsRunning())
	{
		Update();
	}
}

void Game::Update()
{
	switch (game_state)
	{
		case flappy_bird_2D::Game::start:
			Start();
			break;
		case flappy_bird_2D::Game::playing:
			Playing();
			break;
		case flappy_bird_2D::Game::game_over:
			GameOver();
			break;
		default:
			break;
	}
	
	flappy_engine::RenderAll();
}

void Game::Start()
{

}

void Game::Playing()
{
	if (flappy_bird_2D::MouseClick())
	{
		// some thing
	}


}

void Game::GameOver()
{

}

void Game::ChangeGameState(GameState state)
{
	game_state = state;

	switch (game_state)
	{
	case flappy_bird_2D::Game::start:
		CreateStartScene();
		break;
	case flappy_bird_2D::Game::playing:
		CreatePlayingScene();
		break;
	case flappy_bird_2D::Game::game_over:
		CreateGameOverScene();
		break;
	default:
		break;
	}
}
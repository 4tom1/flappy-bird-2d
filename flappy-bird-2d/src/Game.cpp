#include "Game.h"
#include "Settings.h"
#include "Assets.h"

using namespace flappy_bird;

Game::Game()
{
	engine = flappy_engine::InitEngine(WIDTH, HIGHT, FRAME_RATE, "Flappy Bird Game", VOLUME * 100);

	for (size_t i = 0; i < PIPE; i++)
	{
		pipe_c[i] = nullptr;
	}
}

Game::~Game()
{
	delete engine;
}

void Game::Run()
{	
	CreateStartScene();
	
	while (engine->window.isOpen())
	{
		switch (game_state)
		{
			case start:
				Start();
				break;
			case playing:
				Playing();
				break;
			case game_over:
				GameOver();
				break;
			default:
				break;
		}

		engine->RenderAll();
		engine->UpdateAll();
	}
}

void Game::Start()
{
	
}

void Game::Playing()
{
	
}

void Game::GameOver()
{
	
}

void Game::CreateStartScene()
{
	game_state = start;
	
	engine->DeleteAllObj();

	bird = new Bird();
	background = new Background();
	base = new Base();
}

void Game::CreatePlayingScene()
{
	game_state = playing;

	score = new Score();
}

void Game::CreateGameOverScene()
{
	game_state = game_over;
	
	if (points > best_score)
	{
		best_score = points;
	}

	delete score;

	board = new Board();
}
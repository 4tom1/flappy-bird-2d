#include <flappy_engine/flappy_engine.h>

#include "Game.h"
#include "Settings.h"
#include "Assets.h"

using namespace flappy_bird;

Game::Game()
{
	engine = flappy_engine::InitEngine(WIDTH, HIGHT, FRAME_RATE, "Flappy Bird Game", VOLUME * 100);
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
	if (engine->input.MouseClick())
	{
		CreatePlayingScene();
	}
}

void Game::Playing()
{
	static bool mouse_clicked = false;
	static bool spacebar_was_pressed = false;

	if (engine->input.MouseClick()) mouse_clicked = true;
	if (engine->input.IsKeyPressed(flappy_engine::SPACEBAR)) spacebar_was_pressed = true;
	
	if (mouse_clicked && !engine->input.MouseClick() || spacebar_was_pressed && !engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
	{
		bird->Jump();

		mouse_clicked = false;
		spacebar_was_pressed = false;
	}
}

void Game::GameOver()
{
	if (res_but->IsPressed())
	{
		CreateStartScene();
	}
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
	
	if (points[0] * 100 + points[1] * 10 + points[2] > best_score[0] * 100 + best_score[1] * 10 + best_score[2])
	{
		best_score[0] = points[0];
		best_score[1] = points[1];
		best_score[2] = points[2];
	}

	delete score;

	board = new Board(points, best_score);
}
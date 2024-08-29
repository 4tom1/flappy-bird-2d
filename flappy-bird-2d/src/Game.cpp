#include <flappy_engine/flappy_engine.h>

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

void Game::RunTest()
{
	game_state = start;
	
	background = new Background();
	base = new Base(game_state);
	bird = new Bird(game_state);
	
	while (engine->window.isOpen())
	{
		if (game_state == start)
		{
			if (engine->input.MouseClick())
			{
				game_state = playing;
				bird->Jump();
			}
		}
		
		else if (game_state == playing)
		{
			static bool mouse_clicked = false;
			static bool spacebar_was_pressed = false;

			if (!mouse_clicked && engine->input.MouseClick() || !spacebar_was_pressed && engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
			{
				bird->Jump();

				mouse_clicked = true;
				spacebar_was_pressed = true;
			}

			if (!engine->input.MouseClick()) mouse_clicked = false;
			if (!engine->input.IsKeyPressed(flappy_engine::SPACEBAR)) spacebar_was_pressed = false;


		}
		
		engine->RenderAll();
		engine->UpdateAll();
	}
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
		bird->Jump();
	}
}

void Game::Playing()
{
	static bool mouse_clicked = false;
	static bool spacebar_was_pressed = false;

	if (!mouse_clicked && engine->input.MouseClick() || !spacebar_was_pressed && engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
	{
		bird->Jump();

		mouse_clicked = true;
		spacebar_was_pressed = true;
	}

	if (!engine->input.MouseClick()) mouse_clicked = false;
	if (!engine->input.IsKeyPressed(flappy_engine::SPACEBAR)) spacebar_was_pressed = false;


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

	bird = new Bird(game_state);
	background = new Background();
	base = new Base(game_state);
}

void Game::CreatePlayingScene()
{
	game_state = playing;

	score = new Score(points);
	spawner = new Spawner(pipe_c);
	destroyer = new Destroyer(pipe_c);
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
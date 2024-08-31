#include <iostream>

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
	if (engine->input.MouseClick() || engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
	{
		game_state = playing;
		bird.Jump();
	}
}

void Game::Playing()
{
	static bool mouse_clicked = false;
	static bool spacebar_was_pressed = false;

	if (!mouse_clicked && engine->input.MouseClick() || !spacebar_was_pressed && engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
	{
		bird.Jump();

		mouse_clicked = true;
		spacebar_was_pressed = true;
	}

	if (!engine->input.MouseClick()) mouse_clicked = false;
	if (!engine->input.IsKeyPressed(flappy_engine::SPACEBAR)) spacebar_was_pressed = false;

	if (base.IsTriggered() || pipe_m.PipeIsTriggered())
	{
		std::cout << "dupa maryna" << std::endl;
		
		game_state = game_over;
		SetBestScore();
	}

	if (pipe_m.PointCheck())
	{
		std::cout << "point" << std::endl;
		points[2]++;

		if (points[2] >= 10)
		{
			points[2] = 0;
			points[1]++;
		}

		if (points[1] >= 10)
		{
			points[1] = 0;
			points[0]++;
		}
	}
}

void Game::GameOver()
{
	if (res_but.IsPressed())
	{
		game_state = start;
	}
}


void Game::SetBestScore()
{
	if (points[0] * 100 + points[1] * 10 + points[2] > best_score[0] * 100 + best_score[1] * 10 + best_score[2])
	{
		best_score[0] = points[0];
		best_score[1] = points[1];
		best_score[2] = points[2];
	}
}
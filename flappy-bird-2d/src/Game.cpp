#include <iostream>

#include <flappy_engine/flappy_engine.h>

#include "Game.h"
#include "Settings.h"
#include "Assets.h"

using namespace flappy_bird;

Game::Game()
{
	engine = flappy_engine::InitEngine(WIDTH, HIGHT, FRAME_RATE, "Flappy Bird Game", VOLUME * 100);

	bird = new Bird(game_state);
	background = new Background();
	base = new Base(game_state, bird->transform.position);
	score = new Score(points);
	res_but = new RestartButton();
	board = new Board(points, best_score);
	pipe_m = new PipeManager(game_state, bird->transform.position);
}

Game::~Game()
{
	delete engine;
	delete bird;
	delete background;
	delete base;
	delete res_but;
	delete board;
	delete pipe_m;
}

void Game::Run()
{	
	StartScene();
	
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
	static bool mouse_clicked = false;
	static bool spacebar_was_pressed = false;

	if (!mouse_clicked && engine->input.MouseClick() || !spacebar_was_pressed && engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
	{
		PlayingScene();
		bird->Jump();

		mouse_clicked = true;
		spacebar_was_pressed = true;
	}

	if (!engine->input.MouseClick()) mouse_clicked = false;
	if (!engine->input.IsKeyPressed(flappy_engine::SPACEBAR)) spacebar_was_pressed = false;
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

	if (base->IsTriggered() || pipe_m->PipeIsTriggered())
	{
		std::cout << "dupa maryna" << std::endl;

		engine->sound.PlaySound(HIT_AUDIO);
		
		GameOverScene();
	}

	if (pipe_m->PointCheck())
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

		engine->sound.PlaySound(POINT_AUDIO);
	}
}

void Game::GameOver()
{
	static bool but_clicked = false;
	static bool spacebar_was_pressed = false;

	if (!but_clicked && res_but->IsPressed() || !spacebar_was_pressed && engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
	{
		StartScene();

		but_clicked = true;
		spacebar_was_pressed = true;
	}

	if (!res_but->IsPressed()) but_clicked = false;
	if (!engine->input.IsKeyPressed(flappy_engine::SPACEBAR)) spacebar_was_pressed = false;
}

void Game::StartScene()
{
	game_state = start;

	Reset();

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << (int)best_score[i];
	}

	std::cout << std::endl;
}

void Game::PlayingScene()
{
	game_state = playing;

	score->Show();
}

void Game::GameOverScene()
{
	game_state = game_over;

	if (points[0] * 100 + points[1] * 10 + points[2] > best_score[0] * 100 + best_score[1] * 10 + best_score[2])
	{
		best_score[0] = points[0];
		best_score[1] = points[1];
		best_score[2] = points[2];
	}

	score->Hide();
	
	board->Show();
	res_but->Show();
}

void Game::Reset()
{
	for (size_t i = 0; i < 3; i++)
	{
		points[i] = 0;
	}
	
	bird->Reset();
	score->Hide();
	res_but->Hide();
	board->Hide();
	pipe_m->Reset();
}
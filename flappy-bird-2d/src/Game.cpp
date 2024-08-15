#include <flappy_engine/flappy_engine.h>

#include "Game.h"
#include "Settings.h"

using namespace flappy_bird_2D;

Game::Game()
{
	engine = flappy_engine::InitEngine(HIGHT, WIDTH, FRAME_RATE, VOLUME);
}

Game::~Game()
{
	delete engine;
}

void Game::Run()
{	
	ChangeGameState(start);
	
	while (is_running && engine->window.isOpen())
	{
		if (engine->input.IsKeyPressed(flappy_engine::Key::ESC))
		{
			is_running = false;
		}

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

		engine->RenderAllObj();
	}
}

void Game::Start()
{
	engine->UpdateAllObj();

	if (engine->input.MouseClick())
	{
		ChangeGameState(playing);
	}
}

void Game::Playing()
{
	pipe_c_q->PipeCSys();
	
	if (engine->input.MouseClick() || engine->input.IsKeyPressed(flappy_engine::Key::SPACEBAR))
	{
		bird->Jump();
	}

	engine->UpdateAllObj();

	if (pipe_c_q->PointColliderIsTriggered())
	{
		engine->sound.PlaySound("audio_point.waw");
		score++;
	}

	if (pipe_c_q->PipeColliderIsTriggered())
	{
		engine->sound.PlaySound("audio_hit.waw");
		ChangeGameState(game_over);
	}
}

void Game::GameOver()
{
	engine->UpdateAllObj();

	if (res_but->IsPressed())
	{
		engine->sound.PlaySound("audio_wing.waw");
		ChangeGameState(start);
	}
}

void Game::ChangeGameState(GameState state)
{
	game_state = state;

	switch (game_state)
	{
		case start:
			CreateStartScene();
			break;
		case playing:
			CreatePlayingScene();
			break;
		case game_over:
			CreateGameOverScene();
			break;
		default:
			break;
	}
}

void Game::CreateStartScene()
{
	engine->DeleteAllObj();

	bird = new GameObj_Bird();
	background = new GameObj_Background();
	base_v = new Base_vec();
}

void Game::CreatePlayingScene()
{
	score = new Score(&score_points);
	pipe_c_q = new Pipe_c_queue();
	
	bird->Jump();
}

void Game::CreateGameOverScene()
{
	if (score_points > best_score)
	{
		best_score = score_points;
	}

	delete score;
	board = new Board_c(&score_points, &best_score);
}
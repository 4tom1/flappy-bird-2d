#include <flappy_engine.h>

#include "Game.h"

using namespace flappy_bird_2D;

Game::Game()
{
	flappy_engine::InitEngine();
	ChangeGameState(start);
}

Game::~Game()
{
	flappy_engine::DeleteEngine();
}

void Game::Run()
{
	while (is_running)
	{
		Update();
	}
}

void Game::Update()
{
	if (flappy_engine::KeyIsPressed(flappy_engine::Key::ESC))
	{
		SetIsRunning(false);
	}
	
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
	flappy_engine::UpdateAllObj();

	if (flappy_engine::MouseClick())
	{
		ChangeGameState(playing);
	}
}

void Game::Playing()
{
	if (flappy_engine::MouseClick())
	{
		bird->Jump();
	}

	if (pipe_c_stk->PointColliderIsTriggered())
	{
		score++;
	}

	flappy_engine::UpdateAllObj();

	if (pipe_c_stk->BirdGetsHit())
	{
		ChangeGameState(game_over);
	}
}

void Game::GameOver()
{
	flappy_engine::UpdateAllObj();

	if (res_but->IsPressed())
	{
		ChangeGameState(start);
	}
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

void Game::CreateStartScene()
{
	flappy_engine::DeleteAllObj();

	bird = new GameObj_Bird();
	background = new GameObj_Background();
	base_m = new GameObj_Base_multi();
}

void Game::CreatePlayingScene()
{
	score = new GameObj_Score();
	pipe_c_stk = new GameObj_Pipe_c_stack();

	bird->State(playing);
	bird->Jump();
}

void Game::CreateGameOverScene()
{
	delete score;
	board = new GameObj_Board();

	pipe_c_stk->Stop();
	base_m->Stop();

	if (score_points > best_score)
	{
		best_score = score_points;
	}
}

void Game::SetIsRunning(bool set)
{
	is_running = set;
}
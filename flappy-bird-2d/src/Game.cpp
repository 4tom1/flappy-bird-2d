#include <flappy_engine.h>

#include "Game.h"
#include "Settings.h"

using namespace flappy_bird_2D;

Game::Game()
{
	flappy_engine::InitEngine();

	pipe_distance = flappy_engine::Time((int)PIPE_CONSISTENCY);
}

Game::~Game()
{
	flappy_engine::DeleteEngine();
}

void Game::Run()
{
	flappy_engine::TimerStart();
	
	ChangeGameState(start);
	
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
	pipe_c_q->PipeCSys();
	
	if (flappy_engine::MouseClick() || flappy_engine::KeyIsPressed(flappy_engine::Key::SPACEBAR))
	{
		bird->Jump();
	}

	flappy_engine::UpdateAllObj();

	if (pipe_c_q->PointColliderIsTriggered())
	{
		flappy_engine::PlaySound("audio_point.waw");
		score++;
	}

	if (pipe_c_q->PipeColliderIsTriggered())
	{
		flappy_engine::PlaySound("audio_hit.waw");
		ChangeGameState(game_over);
	}
}

void Game::GameOver()
{
	flappy_engine::UpdateAllObj();

	if (res_but->IsPressed())
	{
		flappy_engine::PlaySound("audio_wing.waw");
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
	flappy_engine::DeleteAllObj();

	bird = new GameObj_Bird();
	background = new GameObj_Background();
	base_v = new Base_vec();
}

void Game::CreatePlayingScene()
{
	score = new GameObj_Score();
	pipe_c_q = new Pipe_c_q();
	
	bird->Jump();
}

void Game::CreateGameOverScene()
{
	delete score;
	board = new GameObj_Board();

	if (score_points > best_score)
	{
		best_score = score_points;
	}
}

void Game::SetIsRunning(bool set)
{
	is_running = set;
}

bool Game::IsRunning()
{
	return is_running && flappy_engine::WindowIsOpen();
}
#include "PipeManager.h"

bool flappy_bird::PipeManager::pipe_is_triggered = false;
bool flappy_bird::PipeManager::point = false;

flappy_bird::PipeManager::PipeManager(GameState& game_state, flappy_engine::Position& bird_pos) : game_state(&game_state), bird_pos(&bird_pos) 
{
	for (size_t i = 0; i < PIPE; i++)
	{
		pipes[i].StartPosition(); // set random positions
		pipes[i].pipe1.transform.position.x += i * PIPE_CONSISTENCY;
		pipes[i].pipe2.transform.position.x += i * PIPE_CONSISTENCY;
	}
}

void flappy_bird::PipeManager::Update()
{
	if (*game_state == playing)
	{
		pipe_is_triggered = false;
		point = false;

		for (size_t i = 0; i < PIPE; i++)
		{
			if (pipes[i].PipeIsTriggered())
			{
				pipe_is_triggered = true;
			}

			if (pipes[i].point && bird_pos->x >= pipes[i].pipe2.transform.position.x + pipes[i].pipe2.sprite->GetSize().x / 2)
			{
				pipes[i].point = false;
				point = true;
			}

			if (pipes[i].pipe2.transform.position.x <= PIPE_DESPAWNPOINT)
			{
				pipes[i].point = true;
				pipes[i].StartPosition(); // reset positions and set random hight
			}

			pipes[i].Move();
		}
	}
}
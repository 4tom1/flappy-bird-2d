#include "Spawner.h"

flappy_bird::Spawner::Spawner(PipeC** pipe_c)
{
	this->pipe_c = pipe_c;

	transform.SetPosition(800, 0, 10);
}

void flappy_bird::Spawner::Update()
{
	bool yes = true;

	for (size_t i = 0; i < PIPE; i++)
	{
		if (pipe_c[i]->transform.position.x <= PIPE_CONSISTENCY) 
		{
			yes = false;
			break;
		}
	}

	if (yes)
	{
		for (size_t i = 0; i < PIPE; i++)
		{
			if (!pipe_c[i])
			{
				flappy_engine::Position new_pos(transform.position.x, transform.position.y + ((rand() % RANDOM_SIZE) * 2 - RANDOM_SIZE), transform.position.z);
				pipe_c[i] = new PipeC(new_pos);
				break;
			}
		}
	}
}
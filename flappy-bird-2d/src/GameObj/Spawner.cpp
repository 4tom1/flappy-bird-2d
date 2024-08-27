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
				pipe_c[i] = new PipeC(transform.position);
				break;
			}
		}
	}
}
#include "Destroyer.h"

flappy_bird::Destroyer::Destroyer(PipeC** pipe_c)
{
	this->pipe_c = pipe_c;

	transform.SetPosition(-100, 0, 10);
}

void flappy_bird::Destroyer::Update()
{
	for (size_t i = PIPE; i > 0; --i)
	{
		if (pipe_c[i]->transform.position.x >= transform.position.x)
		{
			delete pipe_c[i];
			pipe_c[i] = nullptr;
		}
	}
}
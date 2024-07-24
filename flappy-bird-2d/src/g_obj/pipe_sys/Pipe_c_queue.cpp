#include "Pipe_c_queue.h"
#include "../../Settings.h"

using namespace flappy_bird_2D;

flappy_bird::Time Pipe_c_queue::last_pipe_created = 0;
flappy_bird::Time Pipe_c_queue::pipe_distance = (double)(0.02 * PIPE_CONSISTENCY);

void Pipe_c_queue::Delete()
{
	if (!empty()) pop();
}

void Pipe_c_queue::Create()
{
	push(Pipe_c());
}

void Pipe_c_queue::PipeCSys()
{
	if (Possible())
	{
		Create();
	}

	if (front().LifeTime() <= (flappy_engine::Time)0)
	{
		Delete();
	}
}

bool Pipe_c_queue::Possible()
{
	if (last_pipe_created >= pipe_distance)
	{
		last_pipe_created = 0;

		return true;
	}

	return false;
}
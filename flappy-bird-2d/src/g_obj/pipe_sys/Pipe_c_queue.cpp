#include "Pipe_c_queue.h"
#include "../../Settings.h"

using namespace flappy_bird_2D;

flappy_bird::Time Pipe_c_queue::last_pipe_created = 0;
flappy_bird::Time Pipe_c_queue::pipe_distance = (double)(0.02 * PIPE_CONSISTENCY);

Pipe_c_queue::Pipe_c_queue()
{
	
}

void Pipe_c_queue::Delete()
{

}

void Pipe_c_queue::Create()
{

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
	 
}


#include "Pipe.h"
#include "../Settings.h"
#include "../Assets.h"

flappy_bird::Pipe::Pipe()
{	
	pipe1.AddComponent(flappy_engine::sprite);
	pipe1.AddComponent(flappy_engine::collider);

	pipe1.sprite->Create(PIPE_DOWN_IMG);

	pipe1.sprite->setScale(PIPE_SIZE, PIPE_SIZE);

	pipe1.collider->SetSize(pipe1.sprite->GetSize().x, pipe1.sprite->GetSize().y);

	pipe1.transform.SetPosition(PIPE_SPAWNPOINT, HIGHT / 2 - PIPE_CLOSENESS / 2 - pipe1.sprite->GetSize().y, PIPE_POS_Z);
	
	pipe2.AddComponent(flappy_engine::sprite);
	pipe2.AddComponent(flappy_engine::collider);
	
	pipe2.sprite->Create(PIPE_UP_IMG);

	pipe2.sprite->setScale(PIPE_SIZE, PIPE_SIZE);

	pipe2.collider->SetSize(pipe2.sprite->GetSize().x, pipe2.sprite->GetSize().y);

	pipe2.transform.SetPosition(PIPE_SPAWNPOINT, HIGHT / 2 + PIPE_CLOSENESS / 2, PIPE_POS_Z);
}

void flappy_bird::Pipe::Move()
{
	pipe1.transform.position.x -= BIRD_SPEED;
	pipe2.transform.position.x -= BIRD_SPEED;
}

void flappy_bird::Pipe::StartPosition()
{
	int random = Random(PIPE_RANDOM * -1, PIPE_RANDOM);
	
	pipe1.transform.SetPosition(PIPE_SPAWNPOINT, HIGHT / 2 - PIPE_CLOSENESS / 2 - pipe1.sprite->GetSize().y - random);
	pipe2.transform.SetPosition(PIPE_SPAWNPOINT, HIGHT / 2 + PIPE_CLOSENESS / 2 - random);
}

float flappy_bird::Pipe::Random(int min, int max)
{
	if (min < max)
	{
		return rand() % (max - min) + min;
	}

	return 1;
}
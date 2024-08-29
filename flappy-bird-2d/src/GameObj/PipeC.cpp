#include "PipeC.h"

flappy_bird::PipeC::PipeC(flappy_engine::Position& position)
{	
	pipe1.transform.SetScale(1, -1);
	pipe1.transform.position = position;
	pipe1.transform.position.y += PIPE_CLOSENESS / 2;

	pipe2.transform.SetScale(1, 1);
	pipe2.transform.position = position;
	pipe2.transform.position.y -= PIPE_CLOSENESS / 2;

	point_collider.collider->SetSize(pipe1.sprite->GetSize().x / 2, PIPE_CLOSENESS);
	point_collider.transform.position = position;
}

void flappy_bird::PipeC::Update()
{
	pipe1.transform.position.x -= BIRD_SPEED;
	pipe2.transform.position.x -= BIRD_SPEED;
	point_collider.transform.position.x -= BIRD_SPEED;
}
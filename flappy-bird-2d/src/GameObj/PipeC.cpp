#include "PipeC.h"

flappy_bird::PipeC::PipeC(flappy_engine::Position& position)
{
	point_collider.transform.SetScale(1, 1);
	point_collider.transform.position = position;
	point_collider.transform.position.y += point_collider.sprite->GetSize().y / 2;
	
	pipe1.transform.SetScale(1, -1);
	pipe1.transform.position = point_collider.transform.position;
	pipe1.transform.position.y += pipe1.sprite->GetSize().y;

	pipe2.transform.SetScale(1, 1);
	pipe2.transform.position = point_collider.transform.position;
	pipe2.transform.position.y -= point_collider.sprite->GetSize().y;
}

void flappy_bird::PipeC::Update()
{
	pipe1.transform.position.x -= BIRD_SPEED;
	pipe2.transform.position.x -= BIRD_SPEED;
	point_collider.transform.position.x -= BIRD_SPEED;
}
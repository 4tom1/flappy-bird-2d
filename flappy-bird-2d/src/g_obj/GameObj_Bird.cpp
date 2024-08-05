#include "GameObj_Bird.h"
#include "../Settings.h"

flappy_bird_2D::GameObj_Bird::GameObj_Bird()
{
	AddComponent(sprite);
	AddComponent(collider);
	
	transform.position = flappy_engine::Position(32, 23, 1);
	*sprite = flappy_engine::Sprite("bird-midflap.png");
	*collider = flappy_engine::Collider(30, 30);
	
	const char* a[] = { "bird-downflap", "bird-midflap.png", "bird-upflap" };
	*animator = flappy_engine::Animator(BIRD_ANIM_SPEED, a);
}

void flappy_bird_2D::GameObj_Bird::Update()
{
	switch (*game_state)
	{
		case start:

			break;
		case playing:
			break;
		case game_over:
			break;
		default:
			break;
	}
	
	if (*game_state == start)
	{
		// movement up, down
	}

	else if (*game_state == playing)
	{
		animator->Update();

		transform.position.y += speed;

		// movement, jump speed, fall speed
	}

	else
	{
		// fall and dying
	}
}

void flappy_bird_2D::GameObj_Bird::Jump()
{
	speed = 2;
}
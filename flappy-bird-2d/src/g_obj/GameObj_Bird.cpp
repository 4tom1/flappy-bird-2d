#include "GameObj_Bird.h"
#include "../Settings.h"

flappy_bird_2D::GameObj_Bird::GameObj_Bird()
{
	const char* a[] = { "bird-downflap", "bird-midflap.png", "bird-upflap" };
	
	transform.position = flappy_engine::Position(32, 23, 1);
	*sprite = new flappy_engine::Sprite("bird-midflap.png");
	*collider = new flappy_engine::Collider(30, 30);
	*animator = new flappy_engine::Animator(BIRD_ANIM_SPEED, a);
}

void flappy_bird_2D::GameObj_Bird::Update()
{
	switch (*game_state)
	{
		case start:
			// movement up, down
			break;
		case playing:
			animator->Update();
			// movement, jump speed, fall speed
			break;
		case game_over:
			// fall and dying
			break;
		default:
			break;
	}
}

void flappy_bird_2D::GameObj_Bird::Jump()
{
	speed = 2;
}
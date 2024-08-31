#include "Bird.h"
#include "../Assets.h"

#include <iostream>

flappy_bird::Bird::Bird(GameState& game_state) : game_state(&game_state)
{
	AddComponent(flappy_engine::sprite);
	AddComponent(flappy_engine::animator);
	sprite->Create(BIRD_MID_IMG);
	
	const char* file_paths[4] = { BIRD_UP_IMG, BIRD_MID_IMG, BIRD_DOWN_IMG, BIRD_MID_IMG };

	animator->Animation(file_paths, BIRD_ANIM_FRAME_RATE);

	sprite->setOrigin(sprite->GetSize().x / 2, sprite->GetSize().y / 2);
	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x, HIGHT / 2 - sprite->GetSize().y / 2, 20);
	transform.SetScale(1.5);

	collider_obj.AddComponent(flappy_engine::collider);
	collider_obj.collider->SetSize(sprite->GetSize().x, sprite->GetSize().y);
	collider_obj.transform.SetPosition(transform.position.x - sprite->GetSize().x / 2, transform.position.y - sprite->GetSize().y / 2);
}

void flappy_bird::Bird::Jump()
{
	acceleration = BIRD_PLAYING_ACCELERATION;
}

void flappy_bird::Bird::Move()
{
	if (*game_state == start)
	{
		if (acceleration > BIRD_START_ACCELERATION) acceleration = BIRD_START_ACCELERATION;
		if (acceleration < BIRD_START_ACCELERATION * -1) acceleration = BIRD_START_ACCELERATION * -1;

		transform.position.y -= acceleration * BIRD_START_JUMP_SPEED;
		transform.position.y -= acceleration * BIRD_START_JUMP_SPEED;
	}

	else if (*game_state == playing)
	{
		if (acceleration > BIRD_PLAYING_ACCELERATION) acceleration = BIRD_PLAYING_ACCELERATION;
		if (acceleration < BIRD_PLAYING_ACCELERATION * -1) acceleration = BIRD_PLAYING_ACCELERATION * -1;

		transform.position.y -= acceleration * BIRD_PLAYING_JUMP_SPEED;
		transform.position.y -= acceleration * BIRD_PLAYING_JUMP_SPEED;
	}
}

void flappy_bird::Bird::Update()
{
	if (*game_state == start)
	{
		animator->Stop();
		
		if (acceleration >= BIRD_START_ACCELERATION)
		{
			direction = true;
		}

		if (acceleration <= BIRD_START_ACCELERATION * -1)
		{
			direction = false;
		}

		if (direction)
		{
			acceleration -= BIRD_ACCELERATION_CHANGE;
		}

		else
		{
			acceleration += BIRD_ACCELERATION_CHANGE;
		}

		Move();
	}

	else if (*game_state == playing)
	{
		acceleration -= BIRD_ACCELERATION_CHANGE;
		
		if (acceleration > BIRD_PLAYING_ACCELERATION * -1)
		{
			animator->Play();
			
			transform.rotation = -15;
		}

		else
		{
			animator->Stop();

			if (transform.rotation < 90)
			{
				transform.rotation += BIRD_PLAYING_ROTATION_SPEED;
			}
		}

		Move();

		collider_obj.transform.position.y = transform.position.y - sprite->GetSize().y / 2;
	}

	else
	{
		animator->Stop();
		
		acceleration -= BIRD_ACCELERATION_CHANGE;

		if (transform.position.y < HIGHT - 100)
		{
			if (transform.rotation < 90)
			{
				transform.rotation += BIRD_PLAYING_ROTATION_SPEED;
			}

			Move();
		}

		else
		{
			transform.position.y = HIGHT - 100;
		}
	}
}
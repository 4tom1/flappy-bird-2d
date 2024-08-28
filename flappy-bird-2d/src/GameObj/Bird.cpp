#include "Bird.h"
#include "../Assets.h"

flappy_bird::Bird::Bird(GameState& game_state) : game_state(&game_state)
{
	AddComponent(flappy_engine::sprite);
	AddComponent(flappy_engine::collider);
	AddComponent(flappy_engine::animator);
	sprite->Create(BIRD_MID_IMG);
	collider->SetSize(sprite->GetSize().x, sprite->GetSize().y);
	
	const char* file_paths[4] = { BIRD_UP_IMG, BIRD_MID_IMG, BIRD_DOWN_IMG, BIRD_MID_IMG };

	animator->Animation(file_paths, BIRD_ANIM_FRAME_RATE);

	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x, HIGHT / 2 - sprite->GetSize().y / 2, 10);
	transform.SetScale(1.5);
}

void flappy_bird::Bird::Jump()
{
	acceleration = BIRD_PLAYING_ACCELERATION;
	transform.rotation += 1;
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

		if (transform.position.y <= HIGHT / 2 - sprite->GetSize().y / 2 - BIRD_START_FLY / 2)
		{
			direction = true;
		}

		if (transform.position.y >= HIGHT / 2 - sprite->GetSize().y / 2 + BIRD_START_FLY / 2)
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
		//animator->Play();
		//
		//acceleration -= BIRD_ACCELERATION_CHANGE;
		//transform.rotation = -30 * acceleration;

		//Move();

		//if (transform.position.y >= HIGHT - 50) transform.position.y = HIGHT - 50; // blocker
	}

	else
	{

	}
}
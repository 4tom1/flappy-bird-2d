#include "Bird.h"
#include "../Assets.h"

flappy_bird::Bird::Bird(GameState& game_state) : game_state(&game_state)
{
	AddComponent(flappy_engine::sprite);
	AddComponent(flappy_engine::animator);
	sprite->Create(BIRD_MID_IMG);
	
	const char* file_paths[4] = { BIRD_UP_IMG, BIRD_MID_IMG, BIRD_DOWN_IMG, BIRD_MID_IMG };

	animator->Animation(file_paths, BIRD_ANIM_FRAME_RATE);

	sprite->setOrigin(sprite->GetSize().x / 2, sprite->GetSize().y / 2);
	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x, HIGHT / 2 - sprite->GetSize().y / 2, BIRD_POS_Z);
	sprite->setScale(1.5, 1.5);

	collider_obj.AddComponent(flappy_engine::collider);
	collider_obj.collider->SetSize(sprite->GetSize().x * BIRD_COLLIDER_WIDTH, sprite->GetSize().y * BIRD_COLLIDER_HIGHT);
	collider_obj.transform.SetPosition(transform.position.x - sprite->GetSize().x / 2, transform.position.y - sprite->GetSize().y / 2, transform.position.z);
}

void flappy_bird::Bird::Reset()
{
	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x, HIGHT / 2 - sprite->GetSize().y / 2, BIRD_POS_Z);
	transform.rotation = 0;
	acceleration = 0;
	direction = true;
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

	else
	{
		if (acceleration > BIRD_PLAYING_ACCELERATION) acceleration = BIRD_PLAYING_ACCELERATION;
		if (acceleration < BIRD_PLAYING_ACCELERATION * -1) acceleration = BIRD_PLAYING_ACCELERATION * -1;

		transform.position.y -= acceleration * BIRD_PLAYING_JUMP_SPEED;
		transform.position.y -= acceleration * BIRD_PLAYING_JUMP_SPEED;
	}
}

void flappy_bird::Bird::Update()
{
	collider_obj.transform.SetPosition(transform.position.x - sprite->GetSize().x / 2, transform.position.y - sprite->GetSize().y / 2, transform.position.z);
	
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
	}

	else
	{
		animator->Stop();
		
		acceleration -= BIRD_ACCELERATION_CHANGE;

		if (transform.position.y < HIGHT - BASE_COLLIDER_HIGHT)
		{
			if (transform.rotation < 90)
			{
				transform.rotation += BIRD_PLAYING_ROTATION_SPEED;
			}

			Move();
		}

		else
		{
			transform.position.y = HIGHT - BASE_COLLIDER_HIGHT;
		}
	}

	if (transform.position.y < HIGHT_LIMIT)
	{
		transform.position.y = HIGHT_LIMIT;
	}
}
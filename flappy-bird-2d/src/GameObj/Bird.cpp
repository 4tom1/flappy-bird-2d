#include "Bird.h"
#include "../Assets.h"

flappy_bird::Bird::Bird(GameState& game_state)
{
	this->game_state = &game_state;

	AddComponent(flappy_engine::sprite);
	AddComponent(flappy_engine::collider);
	AddComponent(flappy_engine::animator);
	sprite->Create(BIRD_MID_IMG);
	collider->SetSize(sprite->GetSize().x, sprite->GetSize().y);
	
	const char* file_paths[4] = { BIRD_UP_IMG, BIRD_MID_IMG, BIRD_DOWN_IMG, BIRD_MID_IMG };

	animator->Create(file_paths, 6);

	transform.SetPosition(WIDTH / 2, HIGHT / 2, 10);
	transform.SetScale(1, 1);
}

void flappy_bird::Bird::Jump()
{
	jump_lenght = BIRD_JUMP_LENGHT;
}

void flappy_bird::Bird::Update()
{
	if (*game_state = start)
	{
		animator->Stop();

		if (transform.position.y >= transform.position.y - BIRD_FLY)
		{
			transform.position.y += BIRD_JUMP_SPEED;
		}

		if (transform.position.y <= transform.position.y + BIRD_FLY)
		{
			transform.position.y -= BIRD_JUMP_SPEED;
		}
	}

	else if (*game_state = playing)
	{
		animator->Play();
		
		if (jump_lenght > BIRD_JUMP_SPEED)
		{
			transform.position.y -= BIRD_JUMP_SPEED;
			jump_lenght -= BIRD_JUMP_SPEED;
			is_jumping = true;
		}

		else
		{
			is_jumping = false;
		}

		if (!is_jumping)
		{
			transform.position.y += BIRD_JUMP_SPEED;
		}
	}

	else
	{

	}
	

}
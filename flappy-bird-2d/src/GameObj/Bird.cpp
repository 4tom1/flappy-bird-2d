#include "Bird.h"
#include "../Assets.h"

flappy_bird::Bird::Bird()
{
	AddComponent(flappy_engine::sprite);
	AddComponent(flappy_engine::collider);
	AddComponent(flappy_engine::animator);
	sprite->Create(BIRD_MID_IMG);
	collider->SetSize(sprite->GetSize().x, sprite->GetSize().y);
	
	const char* file_paths[4] = { BIRD_UP_IMG, BIRD_MID_IMG, BIRD_DOWN_IMG, BIRD_MID_IMG };

	animator->Create(file_paths, 6);

	transform.SetPosition(0, 0, 10);
	transform.SetScale(1, 1);
}

void flappy_bird::Bird::Jump()
{
	jump_lenght = BIRD_JUMP_LENGHT;
}
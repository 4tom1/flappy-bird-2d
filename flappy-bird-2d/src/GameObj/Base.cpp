#include "Base.h"
#include "../Assets.h"
#include "../Settings.h"

flappy_bird::Base::Base(GameState& game_state) : game_state(&game_state)
{
	AddComponent(flappy_engine::sprite);
	AddComponent(flappy_engine::collider);
	sprite->Create(BASE_IMG);
	collider->SetSize(sprite->GetSize().x, sprite->GetSize().y);

	transform.SetPosition(start_pos = 0, 700, 10);
	transform.SetScale(2.2, 2.2);
}

void flappy_bird::Base::Update()
{
	if (*game_state == game_over);

	else
	{
		transform.position.x -= BIRD_SPEED;

		if (-1 * transform.position.x >= sprite->GetSize().x - WIDTH - 37)
		{
			transform.position.x = start_pos;
		}
	}
}
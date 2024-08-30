#include "Base.h"
#include "../Assets.h"
#include "../Settings.h"

flappy_bird::Base::Base(GameState& game_state, flappy_engine::Position& bird_pos) : game_state(&game_state), bird_pos(&bird_pos)
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(BASE_IMG);

	transform.SetPosition(0, HIGHT - 70, 10);
	transform.SetScale(1.7);
}

void flappy_bird::Base::Update()
{
	if (*game_state == game_over);

	else
	{
		transform.position.x -= BIRD_SPEED;

		if (-1 * transform.position.x >= sprite->GetSize().x - WIDTH - 30)
		{
			transform.position.x = 0;
		}
	}
}

bool flappy_bird::Base::IsTriggered()
{
	if (bird_pos->y >= HIGHT - 100)
	{
		return true;
	}

	return false;
}
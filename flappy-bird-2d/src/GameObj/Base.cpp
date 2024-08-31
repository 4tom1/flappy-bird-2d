#include "Base.h"
#include "../Assets.h"
#include "../Settings.h"

flappy_bird::Base::Base(GameState& game_state, flappy_engine::Position& bird_pos) : game_state(&game_state), bird_pos(&bird_pos)
{
	base1.AddComponent(flappy_engine::sprite);
	base1.sprite->Create(BASE_IMG);

	base2.AddComponent(flappy_engine::sprite);
	base2.sprite->Create(BASE_IMG);

	base1.transform.SetPosition(0, HIGHT - 70, 20);
	base1.sprite->setScale(1.7, 1.7);

	base2.transform.SetPosition(base1.sprite->GetSize().x, HIGHT - 70, 20);
	base2.sprite->setScale(1.7, 1.7);
}

void flappy_bird::Base::Update()
{
	if (*game_state == start || *game_state == playing)
	{
		base1.transform.position.x -= BIRD_SPEED;
		base2.transform.position.x -= BIRD_SPEED;

		if (base1.transform.position.x < base1.sprite->GetSize().x * -1)
		{
			base1.transform.position.x = base2.transform.position.x + base2.sprite->GetSize().x;
		}

		if (base2.transform.position.x < base2.sprite->GetSize().x * -1)
		{
			base2.transform.position.x = base1.transform.position.x + base1.sprite->GetSize().x;
		}
	}
}

bool flappy_bird::Base::IsTriggered()
{
	if (bird_pos->y >= HIGHT - BASE_COLLIDER_HIGHT)
	{
		return true;
	}

	return false;
}
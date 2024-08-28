#include "Background.h"
#include "../Assets.h"

flappy_bird::Background::Background()
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(BACKGROUND_IMG);

	transform.SetScale(1.8, 1.8);
	transform.position.y = -150;
}
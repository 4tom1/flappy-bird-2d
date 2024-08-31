#include "Background.h"
#include "../Assets.h"
#include "../Settings.h"

flappy_bird::Background::Background()
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(BACKGROUND_IMG);

	sprite->setScale(1.8, 1.8);
	transform.SetPosition(0, -150, BACKGROUND_POS_Z);
}
#include "Background.h"
#include "../Assets.h"

flappy_bird::Background::Background()
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(BACKGROUND_IMG);
}
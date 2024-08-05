#include "GameObj_Background.h"

flappy_bird_2D::GameObj_Background::GameObj_Background()
{
	AddComponent(sprite);

	transform.position = flappy_engine::Position(32, 23, -1);
	*sprite = flappy_engine::Sprite("background.png");
}
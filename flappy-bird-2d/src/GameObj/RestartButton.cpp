#include "RestartButton.h"
#include "../Assets.h"

flappy_bird::RestartButton::RestartButton()
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(RESTART_IMG);
	SetSize(sprite->GetSize().x, sprite->GetSize().y);

	transform.SetPosition(0, 0, 20);
	transform.SetScale(1, 1);
}
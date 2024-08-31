#include "RestartButton.h"
#include "../Settings.h"
#include "../Assets.h"

flappy_bird::RestartButton::RestartButton()
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(RESTART_IMG);
	
	transform.SetScale(2, 2);
	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x / 2, HIGHT / 2 - sprite->GetSize().y / 2 - 100, 40);

	SetSize(sprite->GetSize().x, sprite->GetSize().y);
}
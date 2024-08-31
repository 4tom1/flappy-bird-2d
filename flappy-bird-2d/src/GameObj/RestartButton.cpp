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

void flappy_bird::RestartButton::Hide()
{
	transform.position.z = 0;
}

void flappy_bird::RestartButton::Show()
{
	transform.position.z = 40;
}
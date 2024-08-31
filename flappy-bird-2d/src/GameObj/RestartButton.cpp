#include "RestartButton.h"
#include "../Settings.h"
#include "../Assets.h"

flappy_bird::RestartButton::RestartButton()
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(RESTART_IMG);
	
	sprite->setScale(2, 2);
	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x / 2, HIGHT / 2 - sprite->GetSize().y / 2 + RESBUT_HIGHT, RESBUT_POS_Z);

	SetSize(sprite->GetSize().x, sprite->GetSize().y);
}

void flappy_bird::RestartButton::Hide()
{
	transform.position.z = 0;
}

void flappy_bird::RestartButton::Show()
{
	transform.position.z = RESBUT_POS_Z;
}
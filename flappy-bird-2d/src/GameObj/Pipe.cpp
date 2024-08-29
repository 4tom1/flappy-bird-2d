#include "Pipe.h"
#include "../Assets.h"

flappy_bird::Pipe::Pipe()
{
	AddComponent(flappy_engine::sprite);
	AddComponent(flappy_engine::collider);
	sprite->Create(PIPE_IMG);
	collider->SetSize(sprite->GetSize().x, sprite->GetSize().y);
}
#include "flappy_engine/GameObjComponents/Collider.h"

void flappy_engine::Collider::Update(Collider& another_collider)
{
	is_triggered = false;
	
	if (transform->position.x <= another_collider.transform->position.x && transform->position.x + size.x >= another_collider.transform->position.x)
	{
		if (transform->position.y <= another_collider.transform->position.y && transform->position.y + size.y >= another_collider.transform->position.y)
		{
			is_triggered = true;
		}

		if (transform->position.y <= another_collider.transform->position.y + another_collider.size.y && 
			transform->position.y + size.y >= another_collider.transform->position.y + another_collider.size.y)
		{
			is_triggered = true;
		}
	}
	
	if (transform->position.x <= another_collider.transform->position.x + another_collider.size.x && 
		transform->position.x + size.x >= another_collider.transform->position.x + another_collider.size.x)
	{
		if (transform->position.y <= another_collider.transform->position.y && transform->position.y + size.y >= another_collider.transform->position.y)
		{
			is_triggered = true;
		}

		if (transform->position.y <= another_collider.transform->position.y + another_collider.size.y &&
			transform->position.y + size.y >= another_collider.transform->position.y + another_collider.size.y)
		{
			is_triggered = true;
		}
	}
}

bool flappy_engine::Collider::IsTriggered()
{
	return is_triggered;
}

void flappy_engine::Collider::SetSize(float x, float y)
{
	size.x = x;
	size.y = y;
}
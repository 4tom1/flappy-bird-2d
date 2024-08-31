#include "flappy_engine/GameObjComponents/Collider.h"

void flappy_engine::Collider::Update(Collider& another_collider)
{
	is_triggered = false;
	
	if (transform->position.x <= another_collider.transform->position.x && 
		transform->position.x + x >= another_collider.transform->position.x)
	{
		if (transform->position.y <= another_collider.transform->position.y && 
			transform->position.y + y >= another_collider.transform->position.y)
		{
			is_triggered = true;
			another_collider.is_triggered = true;
		}

		if (transform->position.y <= another_collider.transform->position.y + another_collider.y && 
			transform->position.y + y >= another_collider.transform->position.y + another_collider.y)
		{
			is_triggered = true;
			another_collider.is_triggered = true;
		}
	}
	
	if (transform->position.x <= another_collider.transform->position.x + another_collider.x && 
		transform->position.x + x >= another_collider.transform->position.x + another_collider.x)
	{
		if (transform->position.y <= another_collider.transform->position.y && 
			transform->position.y + y >= another_collider.transform->position.y)
		{
			is_triggered = true;
			another_collider.is_triggered = true;
		}

		if (transform->position.y <= another_collider.transform->position.y + another_collider.y &&
			transform->position.y + y >= another_collider.transform->position.y + another_collider.y)
		{
			is_triggered = true;
			another_collider.is_triggered = true;
		}
	}
}

void flappy_engine::Collider::SetSize(float factor_x, float factor_y)
{
	x = factor_x;
	y = factor_y;
}

void flappy_engine::Collider::SetSize(float factor)
{
	x = factor;
	y = factor;
}
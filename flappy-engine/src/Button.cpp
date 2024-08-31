#include "flappy_engine/Button.h"
#include "flappy_engine/Core.h"

void flappy_engine::Button::SetSize(float x, float y)
{
	this->x = x;
	this->y = y;
}

void flappy_engine::Button::Update()
{
	is_pressed = false;
	
	if (transform.position.x <= engine->input.GetMousePosition().x && transform.position.x + x >= engine->input.GetMousePosition().x)
	{
		if (transform.position.y <= engine->input.GetMousePosition().y && transform.position.y + y >= engine->input.GetMousePosition().y)
		{
			if (engine->input.MouseClick())
			{
				is_pressed = true;
			}
		}
	}
}
#include "flappy_engine/Input.h"

bool flappy_engine::Input::MouseClick()
{
	if (window->hasFocus())
	{
		return sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right);
	}

	return false;
}

bool flappy_engine::Input::IsKeyPressed(Key key)
{
	if (window->hasFocus())
	{
		switch (key)
		{
			case Key::ESC:
				return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
			case Key::SPACEBAR:
				return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
		}
	}

	return false;
}

void flappy_engine::Input::SetWindow(flappy_engine::Window* window_ptr)
{
	window = window_ptr;
}
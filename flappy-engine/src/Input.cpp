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
			case Key::UP:
				return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
			case Key::DOWN:
				return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
			case Key::LEFT:
				return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
			case Key::RIGHT:
				return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
			default:
				return false;
		}
	}

	return false;
}

sf::Vector2i flappy_engine::Input::GetMousePosition()
{
	return sf::Mouse::getPosition(*window);
}

void flappy_engine::Input::SetWindow(flappy_engine::Window* window_ptr)
{
	window = window_ptr;
}
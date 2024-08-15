#include "flappy_engine/Input.h"

bool flappy_engine::Input::MouseClick()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

bool flappy_engine::Input::IsKeyPressed(Key key)
{
	switch (key)
	{
		case Key::ESC:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
		case Key::SPACEBAR:
			return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	}
}
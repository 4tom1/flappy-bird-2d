#include "flappy_engine/Window.h"

flappy_engine::Window::Window(int width, int high, const char* name)
{
	window.create(sf::VideoMode(width, high), name);
}

void flappy_engine::Window::Update()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void flappy_engine::Window::Render(sf::Sprite sprite)
{
	window.draw(sprite);
}

bool flappy_engine::Window::IsOpen()
{
	return window.isOpen();
}
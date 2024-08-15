#include "flappy_engine/Window.h"

flappy_engine::Window::Window(unsigned int width, unsigned int high, const char* name, unsigned int frame_rate)
{
	create(sf::VideoMode(width, high), name, sf::Style::Close);
	setFramerateLimit(frame_rate);
}

void flappy_engine::Window::Update()
{
	while (pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			close();
		}
	}
}

void flappy_engine::Window::Clear()
{
	clear(sf::Color::Magenta);
}
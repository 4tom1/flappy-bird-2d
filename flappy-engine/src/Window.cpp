#include "flappy_engine/Window.h"

flappy_engine::Window::Window(unsigned int width, unsigned int high, const char* name, unsigned int frame_rate)
{
	create(sf::VideoMode(width, high), name, sf::Style::Close); // SFML setting. Window cannot be resized or set on fullscreen.
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
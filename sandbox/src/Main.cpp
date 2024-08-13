#include <iostream>

#include <flappy_engine/Window.h>

int main()
{
	flappy_engine::Window window(800, 600, "No Name");

	sf::Image img;
	sf::Texture tex;
	sf::Sprite spr;

	if (!img.loadFromFile("assets/sprites/bird-midflap.png"))
	{
		std::cout << "Error." << std::endl;
		std::getchar();
		return 1;
	}
	
	if (!tex.loadFromImage(img))
	{
		std::cout << "Error." << std::endl;
		std::getchar();
		return 1;
	}
	
	spr.setTexture(tex);
	window.Render(spr);

	while (window.IsOpen())
	{
		window.Update();
	}
}
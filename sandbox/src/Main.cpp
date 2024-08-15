#include <iostream>

#include <flappy_engine/Window.h>
#include <flappy_engine/GameObjComponents/Sprite.h>

int main()
{
	flappy_engine::Window window(600, 800, "No Name", 60);
	
	flappy_engine::Sprite sprite;

	if (!sprite.Create("assets/sprites/bird-midflap.png")) return 1;
	
	window.Clear();
	window.draw(sprite);
	window.display();

	while (window.isOpen())
	{
		window.Update();
	}
}
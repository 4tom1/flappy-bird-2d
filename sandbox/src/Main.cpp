#include <iostream>

#include <flappy_engine/Window.h>

int main()
{
	flappy_engine::Window window(800, 600, "No Name");
	
	while (window.IsOpen())
	{
		window.Update();
	}
}
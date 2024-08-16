#include <iostream>

#include <flappy_engine/Window.h>
#include <flappy_engine/Input.h>
#include <flappy_engine/Sound.h>
#include <flappy_engine/GameObj.h>

int main()
{
	flappy_engine::Window window(600, 800, "No Name", 60);
	flappy_engine::Sound sound;
	flappy_engine::Input input;

	input.SetWindow(&window);

	flappy_engine::GameObj game_obj;
	game_obj.AddComponent(flappy_engine::sprite);

	if (!game_obj.sprite->Create("assets/sprites/bird-midflap.png")) return 1;
	
	window.clear();
	window.draw(*game_obj.sprite);
	window.display();

	while (window.isOpen())
	{
		window.Update();

		if (input.MouseClick())
		{
			sound.PlaySound("assets/audio/audio_hit.wav");
		}
	}
}
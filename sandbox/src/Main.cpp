#include <iostream>

#include <flappy_engine/Window.h>
#include <flappy_engine/Input.h>
#include <flappy_engine/Sound.h>
#include <flappy_engine/GameObjComponents/Sprite.h>

int main()
{
	flappy_engine::Window window(600, 800, "No Name", 60);
	flappy_engine::Sound sound;
	flappy_engine::Input input;

	input.SetWindow(&window);

	flappy_engine::Sprite sprite;

	if (!sprite.Create("assets/sprites/bird-midflap.png")) return 1;
	
	window.clear();
	window.draw(sprite);
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
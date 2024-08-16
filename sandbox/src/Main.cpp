#include <iostream>

#include <flappy_engine/Window.h>
#include <flappy_engine/flappy_engine.h>

#define BIRD_IMG "assets/sprites/bird-midflap.png"
#define HIT_AUDIO "assets/audio/audio_hit.wav"

int main()
{
	flappy_engine::Engine* engine = flappy_engine::InitEngine(600, 800, 60, "No name", 100);

	flappy_engine::GameObj obj;
	obj.AddComponent(flappy_engine::sprite);
	obj.sprite->Create(BIRD_IMG);

	while (engine->window.isOpen())
	{
		if (engine->input.MouseClick() || engine->input.IsKeyPressed(flappy_engine::SPACEBAR))
		{
			engine->sound.PlaySound(HIT_AUDIO);
		}
		
		engine->UpdateAll();
		engine->RenderAllObj();
	}
}
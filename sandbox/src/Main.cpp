#include <iostream>

#include <flappy_engine/flappy_engine.h>

#define BIRD_IMG "assets/sprites/bird-midflap.png"
#define BACKGROUND_IMG "assets/sprites/background-night.png"
#define HIT_AUDIO "assets/audio/audio_hit.wav"
#define FRAME_RATE 60
#define SPEED 600

int main()
{
	flappy_engine::Engine* engine = flappy_engine::InitEngine(600, 800, FRAME_RATE, "No name", 100);

	flappy_engine::GameObj bird;
	bird.AddComponent(flappy_engine::sprite);
	bird.sprite->Create(BIRD_IMG);
	
	while (engine->window.isOpen())
	{
		engine->UpdateAll();
		engine->RenderAll();
	}

	std::getchar();
}
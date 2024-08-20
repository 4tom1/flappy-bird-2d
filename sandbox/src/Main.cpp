#include <iostream>

#include <flappy_engine/flappy_engine.h>

#define BIRD_IMG "assets/sprites/bird-midflap.png"
#define BACKGROUND_IMG "assets/sprites/background-night.png"
#define HIT_AUDIO "assets/audio/audio_hit.wav"
#define FRAME_RATE 60
#define SPEED 600


int WinMain()
{
	flappy_engine::Engine* engine = flappy_engine::InitEngine(600, 800, FRAME_RATE, "Sandbox", 100);

	flappy_engine::GameObj background;
	background.AddComponent(flappy_engine::sprite);
	background.sprite->Create(BACKGROUND_IMG);
	background.transform.SetScale(2.2f, 2);
	
	flappy_engine::GameObj bird;
	bird.AddComponent(flappy_engine::sprite);
	bird.sprite->Create(BIRD_IMG);
	bird.transform.SetPosition(300, 400, 1);
	bird.transform.SetScale(1.5);

	while (engine->window.isOpen())
	{
		if (engine->input.IsKeyPressed(flappy_engine::UP)) bird.transform.position.y -= SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::DOWN)) bird.transform.position.y += SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::LEFT)) bird.transform.position.x -= SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::RIGHT)) bird.transform.position.x += SPEED / FRAME_RATE;
		
		engine->UpdateAll();
		engine->RenderAll();
	}
}
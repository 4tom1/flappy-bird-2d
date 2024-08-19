#include <iostream>

#include <flappy_engine/Window.h>
#include <flappy_engine/flappy_engine.h>

#define BIRD_IMG "assets/sprites/bird-midflap.png"
#define HIT_AUDIO "assets/audio/audio_hit.wav"
#define FRAME_RATE 60
#define SPEED 10

int main()
{
	flappy_engine::Engine* engine = flappy_engine::InitEngine(600, 800, FRAME_RATE, "No name", 100);

	flappy_engine::GameObj obj;
	obj.AddComponent(flappy_engine::sprite);
	obj.sprite->Create(BIRD_IMG);

	while (engine->window.isOpen())
	{
		if (engine->input.IsKeyPressed(flappy_engine::UP)) obj.transform.position.y -= SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::DOWN)) obj.transform.position.y += SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::LEFT)) obj.transform.position.x -= SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::RIGHT)) obj.transform.position.x += SPEED / FRAME_RATE;
		
		engine->UpdateAll();
		engine->RenderAll();
	}
}
#include <iostream>

#include <flappy_engine/flappy_engine.h>

#define PIPE_IMG "assets/sprites/pipe-green.png"
#define BIRD_IMG "assets/sprites/bird-midflap.png"
#define BACKGROUND_IMG "assets/sprites/background-night.png"
#define HIT_AUDIO "assets/audio/audio_hit.wav"

#define FRAME_RATE 60
#define SPEED 600


struct Bird : public flappy_engine::GameObj
{
	Bird()
	{
		AddComponent(flappy_engine::sprite);
		AddComponent(flappy_engine::collider);
		sprite->Create(BIRD_IMG);
		collider->SetSize(30.f, 30.f);
		transform.SetPosition(300.f, 400.f, 2.f);
		transform.SetScale(1.5);
	}

	void Update()
	{
		transform.position.y += SPEED / FRAME_RATE;

		if (transform.position.y > 1000)
		{
			delete this;
		}
	}
};

struct Background : public flappy_engine::GameObj
{
	Background()
	{
		AddComponent(flappy_engine::sprite);
		sprite->Create(BACKGROUND_IMG);
		transform.SetScale(2.2f, 2.f);
	}
};

struct Pipe : public flappy_engine::GameObj
{
	Pipe()
	{
		AddComponent(flappy_engine::sprite);
		AddComponent(flappy_engine::collider);
		sprite->Create(PIPE_IMG);
		collider->SetSize(30.f, 300.f);
		transform.position.z = 1.f;
	}

	void Update()
	{
		if (collider->IsTriggered())
		{
			delete this;
		}
	}
};

int main()
{
	flappy_engine::Engine* engine = flappy_engine::InitEngine(600, 800, FRAME_RATE, "Sandbox", 100);

	Bird bird;
	Background backgound;
	Pipe pipe;

	while (engine->window.isOpen())
	{
		if (engine->input.IsKeyPressed(flappy_engine::UP)) bird.transform.position.y -= 2 * SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::LEFT)) bird.transform.position.x -= SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::RIGHT)) bird.transform.position.x += SPEED / FRAME_RATE;
		if (engine->input.IsKeyPressed(flappy_engine::ESC)) break;
		
		engine->UpdateAll();
		engine->RenderAll();
	}
}
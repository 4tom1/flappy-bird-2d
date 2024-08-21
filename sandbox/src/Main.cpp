#include <iostream>
#include <cstdlib>

#include <flappy_engine/flappy_engine.h>

#define ONE_IMG "assets/sprites/1.png"
#define TWO_IMG "assets/sprites/2.png"
#define THREE_IMG "assets/sprites/3.png"
#define FOUR_IMG "assets/sprites/4.png"
#define FIVE_IMG "assets/sprites/5.png"
#define BIRD_IMG "assets/sprites/bird-midflap.png"
#define RESTART_IMG "assets/sprites/restart.png"
#define BACKGROUND_IMG "assets/sprites/background-night.png"
#define COIN_IMG "assets/sprites/coin.png"

#define HIT_AUDIO "assets/audio/audio_hit.wav"

#define FRAME_RATE 60
#define WINDOW_HIGH 800
#define WINDOW_WIDTH 600

#define SPEED 600
#define COIN_LIMIT 6

struct Player : public flappy_engine::GameObj
{
	Player()
	{
		AddComponent(flappy_engine::sprite);
		AddComponent(flappy_engine::collider);

		transform.SetScale(-1, 1);
		sprite->Create(BIRD_IMG);
		collider->SetSize(50.f);

		transform.position.z = 3.f;
	}

	bool direction = true;
};

struct Coin : public flappy_engine::GameObj
{
	Coin()
	{
		AddComponent(flappy_engine::sprite);
		AddComponent(flappy_engine::collider);

		transform.SetScale(1.f);
		sprite->Create(COIN_IMG);
		collider->SetSize(30.f);

		transform.position.z = 2.f;
	}

	bool picked_up = true;
};

struct Points : public flappy_engine::GameObj
{
	Points()
	{

	}

	Points& operator++(int)
	{
		points++;
		return *this;
	}

	unsigned points = 0;
};

struct Background : public flappy_engine::GameObj
{
	Background()
	{
		AddComponent(flappy_engine::sprite);

		transform.SetScale(2.2f, 1.8f);
		sprite->Create(BACKGROUND_IMG);

		transform.position.z = 1.f;
	}
};

struct GameManager : public flappy_engine::GameObj
{
	void Update()
	{
		for (size_t i = 0; i < COIN_LIMIT; i++)
		{
			if (coin_array[i].collider->IsTriggered())
			{
				coin_array[i].picked_up = true;
				points++;

				std::cout << points.points << ' ';
			}
			
			if (coin_array[i].picked_up)
			{
				float x;
				float y;
					
				x = rand() % WINDOW_WIDTH;
				y = rand() % WINDOW_HIGH;

				coin_array[i].transform.SetPosition(x, y);
				coin_array[i].picked_up = false;
			}
		}
	}

	Coin coin_array[COIN_LIMIT];
	Points points;
	Background background;
	Player player;
};

int main()
{	
	flappy_engine::Engine* engine = flappy_engine::InitEngine(WINDOW_WIDTH, WINDOW_HIGH, FRAME_RATE, "Flappy Bird", 100);

	GameManager* game_manager = new GameManager();

	while (engine->window.isOpen())
	{
		if (engine->input.IsKeyPressed(flappy_engine::UP))
		{
			game_manager->player.transform.position.y -= SPEED / FRAME_RATE;
		}
			
		if (engine->input.IsKeyPressed(flappy_engine::DOWN))
		{
			game_manager->player.transform.position.y += SPEED / FRAME_RATE;
		}
			
		if (engine->input.IsKeyPressed(flappy_engine::LEFT))
		{
			game_manager->player.transform.position.x -= SPEED / FRAME_RATE;
		}
		
		if (engine->input.IsKeyPressed(flappy_engine::RIGHT))
		{
			game_manager->player.transform.position.x += SPEED / FRAME_RATE;
		}

		engine->UpdateAll();
		engine->RenderAll();
	}
}
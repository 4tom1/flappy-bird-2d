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

		transform.SetScale(2.f);
		sprite->Create(BIRD_IMG);
		collider->SetSize(50.f);

		transform.position.z = 3.f;
	}

	void Update()
	{
		if (direction && transform.scale.x < 0) sprite->FlipX();
		if (!direction && transform.scale.x > 0) sprite->FlipY();
	}

	bool direction = false;
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

		transform.SetScale(2.f, 2.2f);
		sprite->Create(BACKGROUND_IMG);

		transform.position.z = 1.f;
	}
};

struct GameManager : public flappy_engine::GameObj
{
	GameManager()
	{
		background = new Background();
		player = new Player();
		points = new Points();
	}

	~GameManager()
	{
		delete background;
		delete player;
		delete points;
	}
	
	void Update()
	{
		for (size_t i = 0; i < COIN_LIMIT; i++)
		{
			if (coin_array[i].collider->IsTriggered())
			{
				coin_array[i].transform.position.z = 0.f;
			}
		}

		for (size_t i = 0; i < COIN_LIMIT; i++)
		{
			if (coin_array[i].transform.position.z == 0.f)
			{
				float x;
				float y;
					
				x = rand() % WINDOW_WIDTH;
				y = rand() % WINDOW_HIGH;

				coin_array[i].transform.SetPosition(x, y, 2.f);
			}
		}
	}

	Coin coin_array[COIN_LIMIT];
	Points* points;
	Background* background;
	Player* player;
};

int main()
{	
	flappy_engine::Engine* engine = flappy_engine::InitEngine(WINDOW_WIDTH, WINDOW_HIGH, FRAME_RATE, "Flappy Bird", 100);

	GameManager game_manager;

	while (engine->window.isOpen())
	{
		if (engine->input.IsKeyPressed(flappy_engine::UP))
		{
			game_manager.player->transform.position.y -= SPEED / FRAME_RATE;
		}
			
		if (engine->input.IsKeyPressed(flappy_engine::DOWN))
		{
			game_manager.player->transform.position.y += SPEED / FRAME_RATE;
		}
			
		if (engine->input.IsKeyPressed(flappy_engine::LEFT))
		{
			game_manager.player->transform.position.x -= SPEED / FRAME_RATE;
			game_manager.player->direction = false;
		}
		
		if (engine->input.IsKeyPressed(flappy_engine::RIGHT))
		{
			game_manager.player->transform.position.x += SPEED / FRAME_RATE;
			game_manager.player->direction = true;
		}

		engine->UpdateAll();
		engine->RenderAll();
	}
}
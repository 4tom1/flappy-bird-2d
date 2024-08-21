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
	Coin(float x, float y)
	{
		AddComponent(flappy_engine::sprite);
		AddComponent(flappy_engine::collider);

		transform.SetScale(1.f);
		sprite->Create(COIN_IMG);
		collider->SetSize(30.f);

		transform.position.x = x;
		transform.position.y = y;
	}
};

struct Points : public flappy_engine::GameObj
{
	Points()
	{

	}

	Points& operator++()
	{
		points++;
	}

	unsigned points = 0;
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

		for (size_t i = 0; i < COIN_LIMIT; i++)
		{
			if (coin_ptr_array[i]) delete coin_ptr_array[i];
		}
	}
	
	void Update()
	{
		for (size_t i = 0; i < COIN_LIMIT; i++)
		{
			if (coin_ptr_array[i])
			{
				if (coin_ptr_array[i]->collider->IsTriggered())
				{
					delete coin_ptr_array[i];
					coin_ptr_array[i] = nullptr;

					coins--;
					*points++;
				}
			}
		}

		if (coins < COIN_LIMIT)
		{
			for (size_t i = 0; i < COIN_LIMIT; i++)
			{
				if (!coin_ptr_array[i])
				{
					int x;
					int y;
					
					x = rand() % WINDOW_WIDTH;
					y = rand() % WINDOW_HIGH;

					coin_ptr_array[i] = new Coin(x, y);
				}
			}
		}
	}

	unsigned int coins = 6;
	Coin* coin_ptr_array[COIN_LIMIT];
	Points* points;
	Background* background;
	Player* player;
};

struct Background : public flappy_engine::GameObj
{
	Background()
	{
		AddComponent(flappy_engine::sprite);

		transform.SetScale(2.f, 2.2f);
		sprite->Create(BACKGROUND_IMG);
	}
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
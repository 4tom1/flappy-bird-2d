#include <iostream>
#include <cstdlib>

#include <flappy_engine/flappy_engine.h>

#define ONE_IMG "assets/sprites/1.png"
#define TWO_IMG "assets/sprites/2.png"
#define THREE_IMG "assets/sprites/3.png"
#define FOUR_IMG "assets/sprites/4.png"
#define FIVE_IMG "assets/sprites/5.png"
#define RESTART_IMG "assets/sprites/restart.png"
#define BACKGROUND_IMG "assets/sprites/background-night.png"
#define COIN_IMG "assets/sprites/coin.png"

#define BIRD_UP_IMG "assets/sprites/bird-upflap.png"
#define BIRD_MID_IMG "assets/sprites/bird-midflap.png"
#define BIRD_DOWN_IMG "assets/sprites/bird-downflap.png"

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
		AddComponent(flappy_engine::animator);

		transform.SetScale(3.f);
		sprite->Create(BIRD_MID_IMG);
		collider->SetSize(sprite->GetSize().x, sprite->GetSize().y);
		
		const char* images[] = { BIRD_DOWN_IMG, BIRD_MID_IMG, BIRD_UP_IMG, BIRD_MID_IMG };
		animator->Create(images, 12);

		transform.position.z = 3.f;
	}

	void Update()
	{
		if (engine->input.IsKeyPressed(flappy_engine::UP))
		{
			transform.position.y -= SPEED / FRAME_RATE;
		}

		if (engine->input.IsKeyPressed(flappy_engine::DOWN))
		{
			transform.position.y += SPEED / FRAME_RATE;
		}

		if (engine->input.IsKeyPressed(flappy_engine::LEFT))
		{
			transform.position.x -= SPEED / FRAME_RATE;
		}

		if (engine->input.IsKeyPressed(flappy_engine::RIGHT))
		{
			transform.position.x += SPEED / FRAME_RATE;
		}
	}
};

struct Coin : public flappy_engine::GameObj
{
	Coin()
	{
		AddComponent(flappy_engine::sprite);
		AddComponent(flappy_engine::collider);

		transform.SetScale(1.f);
		sprite->Create(COIN_IMG);
		collider->SetSize((sprite->GetSize().x, sprite->GetSize().y));

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

				engine->sound.PlaySound(HIT_AUDIO);

				std::cout << points.points << ' ';
			}
			
			if (coin_array[i].picked_up)
			{
				float x;
				float y;
					
				x = (rand() % WINDOW_WIDTH / 50) * 50;
				y = (rand() % WINDOW_HIGH / 50) * 50;

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
		engine->UpdateAll();
		engine->RenderAll();
	}

	delete game_manager;
}
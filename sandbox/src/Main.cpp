#include <flappy_engine/flappy_engine.h>
#include <iostream>

#define ONE_IMG "assets/sprites/1.png"
#define TWO_IMG "assets/sprites/2.png"
#define THREE_IMG "assets/sprites/3.png"
#define FOUR_IMG "assets/sprites/4.png"
#define FIVE_IMG "assets/sprites/5.png"
#define SIX_IMG "assets/sprites/6.png"
#define SEVEN_IMG "assets/sprites/7.png"
#define EIGHT_IMG "assets/sprites/8.png"
#define NINE_IMG "assets/sprites/9.png"
#define ZERO_IMG "assets/sprites/0.png"
#define BACKGROUND_DAY_IMG "assets/sprites/background-day.png"
#define BACKGROUND_NIGHT_IMG "assets/sprites/background-night.png"
#define BANANA_IMG "assets/sprites/banana.png"
#define BAPHOMET_IMG "assets/sprites/Baphomet.png"

#define HIT_AUDIO "assets/audio/audio_hit.wav"
#define WING_AUDIO "assets/audio/audio_wing.wav"
#define ETO_AUDIO "assets/audio/etoneht321.wav"

#define FRAME_RATE 60
#define WINDOW_HIGH 800
#define WINDOW_WIDTH 600

using namespace flappy_engine;

struct Banana : public Button
{
	Banana()
	{
		AddComponent(Component::sprite);
		sprite->Create(BANANA_IMG);
		
		transform.SetScale(0.4);
		transform.SetPosition((WINDOW_WIDTH / 2) - (sprite->GetSize().x / 2), (WINDOW_HIGH / 2) - (sprite->GetSize().y / 2), 2);
		
		SetSize(sprite->GetSize().x, sprite->GetSize().y);
	}
};

struct Number : public GameObj
{
	Number()
	{
		AddComponent(Component::sprite);
		sprite->Create(ZERO_IMG);
	}

	void SetNumber(int num)
	{
		switch (num)
		{
			case 0:
				sprite->Create(ZERO_IMG);
				break;
			case 1:
				sprite->Create(ONE_IMG);
				break;
			case 2:
				sprite->Create(TWO_IMG);
				break;
			case 3:
				sprite->Create(THREE_IMG);
				break;
			case 4:
				sprite->Create(FOUR_IMG);
				break;
			case 5:
				sprite->Create(FIVE_IMG);
				break;
			case 6:
				sprite->Create(SIX_IMG);
				break;
			case 7:
				sprite->Create(SEVEN_IMG);
				break;
			case 8:
				sprite->Create(EIGHT_IMG);
				break;
			case 9:
				sprite->Create(NINE_IMG);
				break;
			default:
				break;
		}
	}
};

struct Background : public GameObj
{
	Background()
	{
		AddComponent(Component::sprite);
		sprite->Create(BACKGROUND_DAY_IMG);

		transform.SetPosition(0, -80);
		transform.SetScale(2.1, 2);
	}

	void Night()
	{
		sprite->Create(BACKGROUND_NIGHT_IMG);
	}
};

struct Points : public GameObj
{
	Points()
	{
		numbers[0].transform.SetPosition((WINDOW_WIDTH / 2) - (numbers[0].sprite->GetSize().x * 1.5), 20, 4);
		numbers[1].transform.SetPosition(numbers[0].transform.position.x + numbers[1].sprite->GetSize().x, 20, 4);
		numbers[2].transform.SetPosition(numbers[1].transform.position.x + numbers[2].sprite->GetSize().x, 20, 4);
	}
	
	void Update()
	{	
		if (ones == 6 && tens == 6 && hundreds == 6)
		{
			reached_max = true;
		}
		
		numbers[0].SetNumber(hundreds);
		numbers[1].SetNumber(tens);
		numbers[2].SetNumber(ones);
	}

	Points& operator++(int)
	{
		
		if (!reached_max) ones++;

		if (ones >= 10)
		{
			ones = 0;
			tens++;

			engine->sound.PlaySound(WING_AUDIO);
		}

		if (tens >= 10)
		{
			tens = 0;
			hundreds++;

			engine->sound.PlaySound(HIT_AUDIO);
		}

		return *this;
	}

	Number numbers[3];

	unsigned int ones = 0;
	unsigned int tens = 0;
	unsigned int hundreds = 0;

	bool reached_max = false;
};

struct MysteryThing : public GameObj
{
	MysteryThing()
	{
		AddComponent(Component::sprite);
		sprite->Create(BAPHOMET_IMG);
		transform.SetPosition(-50, -50, 3);
		transform.SetScale(2);
	}
};

int main()
{	
	Engine* engine = InitEngine(WINDOW_WIDTH, WINDOW_HIGH, 60, "Banana Game!", 100);

	Banana banana;
	Points points;
	Background background;

	bool was_pressed = false;
	bool one_time = true;

	while (engine->window.isOpen())
	{
		if (banana.IsPressed())
		{
			was_pressed = true;
		}
		
		if (was_pressed && !banana.IsPressed())
		{
			points++;
			was_pressed = false;
		}

		if (points.reached_max && one_time)
		{	
			engine->sound.PlaySound(ETO_AUDIO);
			new MysteryThing;

			one_time = false;
		}

		engine->UpdateAll();
		engine->RenderAll();
	}
}
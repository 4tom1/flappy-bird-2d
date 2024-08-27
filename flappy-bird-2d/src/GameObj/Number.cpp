#include "Number.h"
#include "../Assets.h"

flappy_bird::Number::Number()
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(ZERO_IMG);
}

void flappy_bird::Number::Set(unsigned int number)
{
	switch (number)
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
#include "Score.h"

flappy_bird::Score::Score(unsigned char* points)
{
	this->points = points;
	
	for (size_t i = 0; i < 3; i++)
	{
		score[i].Set(0);
	}
}

void flappy_bird::Score::Set(unsigned char* score)
{
	for (size_t i = 0; i < 3; i++)
	{
		this->score[i].Set(score[i]);
	}
}

void flappy_bird::Score::Update()
{
	Set(points);
}
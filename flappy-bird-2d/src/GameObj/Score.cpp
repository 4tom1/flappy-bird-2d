#include "Score.h"
#include "../Settings.h"

flappy_bird::Score::Score(unsigned char* points)
{
	this->points = points;
	
	for (size_t i = 0; i < 3; i++)
	{
		score[i].Set(0);
	}

	score[0].transform.SetPosition((WIDTH / 2) - score[0].sprite->GetSize().x * 1.5, 20, SCORE_POS_Z);
	score[1].transform.SetPosition(score[0].transform.position.x + (score[1].sprite->GetSize().x), 20, SCORE_POS_Z);
	score[2].transform.SetPosition(score[1].transform.position.x + (score[2].sprite->GetSize().x), 20, SCORE_POS_Z);
}

void flappy_bird::Score::Set()
{
	for (size_t i = 0; i < 3; i++)
	{
		score[i].Set(points[i]);
	}
}

void flappy_bird::Score::Hide()
{
	for (size_t i = 0; i < 3; i++)
	{
		score[i].transform.position.z = 0;
	}
}

void flappy_bird::Score::Show()
{
	for (size_t i = 0; i < 3; i++)
	{
		score[i].transform.position.z = SCORE_POS_Z;
	}
}

void flappy_bird::Score::Update()
{
	Set();
}
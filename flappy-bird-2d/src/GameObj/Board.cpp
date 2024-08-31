#include "Board.h"
#include "../Settings.h"
#include "../Assets.h"

flappy_bird::Board::Board(unsigned char* points, unsigned char* best) : points(points), best(best)
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(BOARD_IMG);

	sprite->setScale(3, 3);
	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x / 2, HIGHT / 2 - sprite->GetSize().y / 2 - BOARD_HIGHT, BOARD_POS_Z);


	for (size_t i = 0; i < 3; i++)
	{
		this->score[i].sprite->setScale(BOARD_NUMBER_SIZE, BOARD_NUMBER_SIZE);
		this->best_score[i].sprite->setScale(BOARD_NUMBER_SIZE, BOARD_NUMBER_SIZE);
	}

	this->score[0].transform.SetPosition(transform.position.x + sprite->GetSize().x / 2 - this->score[0].sprite->GetSize().x * 1.5, transform.position.y + BOARD_SCORE_HIGHT, transform.position.z + 1);
	this->score[1].transform.SetPosition(this->score[0].transform.position.x + this->score[0].sprite->GetSize().x, transform.position.y + BOARD_SCORE_HIGHT, transform.position.z + 1);
	this->score[2].transform.SetPosition(this->score[1].transform.position.x + this->score[0].sprite->GetSize().x, transform.position.y + BOARD_SCORE_HIGHT, transform.position.z + 1);

	this->best_score[0].transform.SetPosition(transform.position.x + sprite->GetSize().x / 2 - this->best_score[0].sprite->GetSize().x * 1.5, transform.position.y + BOARD_BEST_HIGHT, transform.position.z + 1);
	this->best_score[1].transform.SetPosition(this->best_score[0].transform.position.x + this->best_score[0].sprite->GetSize().x, transform.position.y + BOARD_BEST_HIGHT, transform.position.z + 1);
	this->best_score[2].transform.SetPosition(this->best_score[1].transform.position.x + this->best_score[0].sprite->GetSize().x, transform.position.y + BOARD_BEST_HIGHT, transform.position.z + 1);
}

void flappy_bird::Board::Set()
{
	for (size_t i = 0; i < 3; i++)
	{
		score[i].Set(points[i]);
		best_score[i].Set(best[i]);
	}
}

void flappy_bird::Board::Hide()
{
	transform.position.z = 0;

	for (size_t i = 0; i < 3; i++)
	{
		score[i].transform.position.z = 0;
		best_score[i].transform.position.z = 0;
	}
}

void flappy_bird::Board::Show()
{
	transform.position.z = BOARD_POS_Z;

	for (size_t i = 0; i < 3; i++)
	{
		score[i].transform.position.z = transform.position.z + 1;
		best_score[i].transform.position.z = transform.position.z + 1;
	}

	Set();
}
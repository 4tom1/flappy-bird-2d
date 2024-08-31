#include "Board.h"
#include "../Settings.h"
#include "../Assets.h"

flappy_bird::Board::Board(unsigned char* score, unsigned char* best_score)
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(BOARD_IMG);

	sprite->setScale(3, 3);
	transform.SetPosition(WIDTH / 2 - sprite->GetSize().x / 2, HIGHT / 2 - sprite->GetSize().y / 2, 30);


	for (size_t i = 0; i < 3; i++)
	{
		this->score[i].Set(score[i]);
		this->best_score[i].Set(best_score[i]);
	}

	this->score[0].transform.SetPosition(transform.position.x + this->score[0].sprite->GetSize().x, transform.position.y, transform.position.z + 1);
	this->score[1].transform.SetPosition(this->score[0].transform.position.x + this->score[0].sprite->GetSize().x, transform.position.y, transform.position.z + 1);
	this->score[2].transform.SetPosition(this->score[1].transform.position.x + this->score[0].sprite->GetSize().x, transform.position.y, transform.position.z + 1);

	this->best_score[0].transform.SetPosition(transform.position.x + this->best_score[0].sprite->GetSize().x, transform.position.y + this->best_score[0].sprite->GetSize().y, transform.position.z + 1);
	this->best_score[1].transform.SetPosition(this->best_score[0].transform.position.x + this->best_score[0].sprite->GetSize().x, transform.position.y + this->best_score[0].sprite->GetSize().y, transform.position.z + 1);
	this->best_score[2].transform.SetPosition(this->best_score[1].transform.position.x + this->best_score[0].sprite->GetSize().x, transform.position.y + this->best_score[0].sprite->GetSize().y, transform.position.z + 1);
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
	transform.position.z = 30;

	for (size_t i = 0; i < 3; i++)
	{
		score[i].transform.position.z = transform.position.z + 1;
		best_score[i].transform.position.z = transform.position.z + 1;
	}
}
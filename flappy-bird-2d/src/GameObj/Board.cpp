#include "Board.h"
#include "../Assets.h"

flappy_bird::Board::Board(unsigned char* score, unsigned char* best_score)
{
	AddComponent(flappy_engine::sprite);
	sprite->Create(BOARD_IMG);

	transform.SetPosition(0, 0, 20);
	transform.SetScale(1, 1);

	for (size_t i = 0; i < 3; i++)
	{
		this->score[i].Set(score[i]);
		this->best_score[i].Set(best_score[i]);
	}

	this->score[0].transform.SetPosition(transform.position.x, transform.position.y, transform.position.z + 1);
	this->score[1].transform.SetPosition(transform.position.x, transform.position.y, transform.position.z + 1);
	this->score[2].transform.SetPosition(transform.position.x, transform.position.y, transform.position.z + 1);

	this->best_score[0].transform.SetPosition(transform.position.x, transform.position.y, transform.position.z + 1);
	this->best_score[1].transform.SetPosition(transform.position.x, transform.position.y, transform.position.z + 1);
	this->best_score[2].transform.SetPosition(transform.position.x, transform.position.y, transform.position.z + 1);
}
#include "GameObj_Board.h"

flappy_bird_2D::GameObj_Board::GameObj_Board()
{
	AddComponent(sprite);

	transform.position = flappy_engine::Position(32, 23, 2);
	*sprite = flappy_engine::Sprite("board.png");
}
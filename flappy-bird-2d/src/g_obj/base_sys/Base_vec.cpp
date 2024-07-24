#include "Base_vec.h"

using namespace flappy_bird_2D;

Base_vec::Base_vec()
{
	for (auto i = 0; i < BASE_QUANTITY; i++)
	{
		bases[i] = GameObj_Base(i);
	}
}
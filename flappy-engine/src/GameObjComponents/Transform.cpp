#include "flappy_engine/GameObjComponents/Transform.h"

void flappy_engine::Transform::SetPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void flappy_engine::Transform::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}
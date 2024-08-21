#include "flappy_engine/GameObj.h"

flappy_engine::GameObjManager* flappy_engine::GameObj::game_obj_manager = nullptr;

void flappy_engine::GameObj::AddComponent(flappy_engine::Component com)
{
	switch (com)
	{
		case flappy_engine::sprite:
			if (!sprite) sprite = new Sprite(&transform);
			break;
		case flappy_engine::collider:
			if (!collider) collider = new Collider(&transform);
			break;
		default:
			break;
	}
}

void flappy_engine::GameObj::DeleteComponent(flappy_engine::Component com)
{
	switch (com)
	{
		case flappy_engine::sprite:
			if (sprite) delete sprite;
			sprite = nullptr;
			break;
		case flappy_engine::collider:
			if (collider) delete collider;
			collider = nullptr;
			break;
		default:
			break;
	}
}


void flappy_engine::GameObj::SetGameObjManager(GameObjManager* gom)
{
	game_obj_manager = gom;
}

void flappy_engine::GameObj::Update() {}
#include "flappy_engine/GameObj.h"

flappy_engine::GameObjManager* flappy_engine::GameObj::game_obj_manager = nullptr;

flappy_engine::GameObj::GameObj()
{
	// game_obj_manager->AddGameObj(this);
}

flappy_engine::GameObj::~GameObj()
{
	if (sprite) delete sprite;
	if (collider) delete collider;
}

void flappy_engine::GameObj::AddComponent(flappy_engine::Components com)
{
	switch (com)
	{
		case flappy_engine::sprite:
			sprite = new Sprite();
			break;
		case flappy_engine::collider:
			collider = new Collider();
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
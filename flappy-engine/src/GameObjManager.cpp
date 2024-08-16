#include "flappy_engine/GameObjManager.h"

void flappy_engine::GameObjManager::AddGameObj(GameObj* new_game_obj)
{
	game_obj_ptr_vec.push_back(new_game_obj);
}

void flappy_engine::GameObjManager::UpdateAll()
{
	for (size_t i = 0; i < game_obj_ptr_vec.size(); i++)
	{
		game_obj_ptr_vec[i]->Update();
	}
}

void flappy_engine::GameObjManager::DeleteAll()
{
	game_obj_ptr_vec.clear();
}

flappy_engine::GameObj& flappy_engine::GameObjManager::operator[](int idx) const
{
	return *(game_obj_ptr_vec[idx]);
}

size_t flappy_engine::GameObjManager::VectorSize()
{
	return game_obj_ptr_vec.size();
}

flappy_engine::GameObj::GameObj()
{
	game_obj_manager->AddGameObj(this);
}
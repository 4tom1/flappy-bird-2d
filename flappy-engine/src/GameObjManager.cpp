#include "flappy_engine/GameObjManager.h"

void flappy_engine::GameObjManager::AddGameObj(GameObj* new_game_obj)
{
	game_obj_ptr_vec.push_back(new_game_obj);
}

void flappy_engine::GameObjManager::DeleteGameObj(GameObj* old_game_obj)
{
	for (size_t i = 0; i < game_obj_ptr_vec.size(); i++)
	{
		if (game_obj_ptr_vec[i] == old_game_obj)
		{
			for (size_t j = i; j < game_obj_ptr_vec.size() - 1; j++)
			{
				game_obj_ptr_vec[j] = game_obj_ptr_vec[j + 1];
			}

			game_obj_ptr_vec.pop_back();
			break;
		}
	}
}

void flappy_engine::GameObjManager::UpdateAllObj()
{
	for (size_t i = 0; i < game_obj_ptr_vec.size(); i++)
	{
		game_obj_ptr_vec[i]->Update();
		
		if (game_obj_ptr_vec[i]->sprite) game_obj_ptr_vec[i]->sprite->Update();
		if (game_obj_ptr_vec[i]->collider) game_obj_ptr_vec[i]->collider->Update();
	}
}

void flappy_engine::GameObjManager::DeleteAllObj()
{
	for (size_t i = 0; i < game_obj_ptr_vec.size(); i++)
	{
		delete game_obj_ptr_vec[i];
	}
}

flappy_engine::GameObj* flappy_engine::GameObjManager::operator[](size_t idx)
{
	return game_obj_ptr_vec[idx];
}

size_t flappy_engine::GameObjManager::Size()
{
	return game_obj_ptr_vec.size();
}

void flappy_engine::GameObjManager::Sort()
{
	bool unsolved;

	do
	{
		unsolved = false;

		for (size_t i = 0; i < game_obj_ptr_vec.size() - 1; i++)
		{
			if (game_obj_ptr_vec[i]->transform.position.z < game_obj_ptr_vec[i + 1]->transform.position.z)
			{
				GameObj* helper = game_obj_ptr_vec[i];
				game_obj_ptr_vec[i] = game_obj_ptr_vec[i + 1];
				game_obj_ptr_vec[i + 1] = helper;

				unsolved = true;
			}
		}

	} while (unsolved);
}

flappy_engine::GameObj::GameObj()
{
	game_obj_manager->AddGameObj(this);
}

flappy_engine::GameObj::~GameObj()
{
	game_obj_manager->DeleteGameObj(this);

	if (sprite) delete sprite;
	if (collider) delete collider;
}
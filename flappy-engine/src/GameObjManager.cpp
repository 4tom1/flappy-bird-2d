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
				game_obj_ptr_vec[j + 1] = nullptr;
			}

			// without pop

			break;
		}
	}
}

void flappy_engine::GameObjManager::UpdateAllObj()
{
	for (size_t i = 0; i < game_obj_ptr_vec.size(); i++)
	{
		if (game_obj_ptr_vec[i])
		{
			game_obj_ptr_vec[i]->Update();

			if (game_obj_ptr_vec[i]->sprite) game_obj_ptr_vec[i]->sprite->Update();
			if (game_obj_ptr_vec[i]->animator) game_obj_ptr_vec[i]->animator->Update();

			for (size_t j = 0; j < game_obj_ptr_vec.size(); j++)
			{
				if (i != j)
				{
					if (game_obj_ptr_vec[i]->collider && game_obj_ptr_vec[j]->collider) game_obj_ptr_vec[i]->collider->Update(*game_obj_ptr_vec[j]->collider);
				}
			}
		}
	}
}

flappy_engine::GameObj* flappy_engine::GameObjManager::operator[](size_t idx) const
{
	return game_obj_ptr_vec[idx];
}

size_t flappy_engine::GameObjManager::Size() const
{
	return game_obj_ptr_vec.size();
}

void flappy_engine::GameObjManager::Sort() // Bubble sort algorithm.
{
	if (game_obj_ptr_vec.size() > 0)
	{
		bool unsolved = false;

		do
		{
			unsolved = false;

			for (size_t i = 0; i < game_obj_ptr_vec.size() - 1; i++)
			{
				if (game_obj_ptr_vec[i]->transform.position.z > game_obj_ptr_vec[i + 1]->transform.position.z)
				{
					GameObj* helper = game_obj_ptr_vec[i];
					game_obj_ptr_vec[i] = game_obj_ptr_vec[i + 1];
					game_obj_ptr_vec[i + 1] = helper;

					unsolved = true;
				}
			}

		} while (unsolved);
	}
}
#include "flappy_engine/GameObjManager.h"

void flappy_engine::GameObjManager::AddGameObj(GameObj* new_game_obj)
{
	game_obj_ptr_list.push_back(new_game_obj);
	Sort();
}

void flappy_engine::GameObjManager::DeleteGameObj(GameObj* old_game_obj)
{
	game_obj_ptr_list.remove(old_game_obj);
}

void flappy_engine::GameObjManager::UpdateAllObj()
{
	for (std::list<GameObj*>::iterator it = game_obj_ptr_list.begin(); it != game_obj_ptr_list.end(); ++it)
	{
		(*it)->Update();
		
		if ((*it)->sprite) (*it)->sprite->Update();
		if ((*it)->collider) (*it)->collider->Update();
	}
}

void flappy_engine::GameObjManager::DeleteAllObj()
{
	for (std::list<GameObj*>::iterator it = game_obj_ptr_list.begin(); it != game_obj_ptr_list.end(); ++it)
	{
		delete (*it);
	}
}

flappy_engine::GameObj* flappy_engine::GameObjManager::operator[](size_t  idx)
{
	std::list<GameObj*>::iterator it = game_obj_ptr_list.begin();

	for (size_t i = 0; i < idx; i++)
	{
		it++;
	}
	
	return *(it);
}

size_t flappy_engine::GameObjManager::Size()
{
	return game_obj_ptr_list.size();
}

void flappy_engine::GameObjManager::Sort()
{
	//bool unsolved;

	//do
	//{
	//	unsolved = false;

	//	std::list<GameObj*>::iterator it1 = game_obj_ptr_list.begin();
	//	std::list<GameObj*>::iterator it2 = it1;

	//	for (; it1 != --game_obj_ptr_list.end(); ++it1)
	//	{
	//		it2 = it1;
	//		it2++;

	//		if ((*it1)->transform.position.z < (*it2)->transform.position.z)
	//		{
	//			GameObj* helper = *it1;
	//			*it1 = *it2;
	//			*it2 = helper;

	//			unsolved = true;
	//		}
	//	}

	//} while (unsolved);
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
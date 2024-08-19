#ifndef _FLAPPY_ENGINE_GAMEOBJMANAGER_
#define _FLAPPY_ENGINE_GAMEOBJMANAGER_

#include <list>

#include <flappy_engine/GameObj.h>

namespace flappy_engine {

	class GameObjManager
	{
		public:

			void AddGameObj(GameObj* new_game_obj);
			void DeleteGameObj(GameObj* old_game_obj);
			void DeleteAllObj();
			void UpdateAllObj();
			void Sort();
			size_t Size();

			GameObj* operator[](size_t idx);

		private:

			std::list<GameObj*> game_obj_ptr_list;
	};
}

#endif
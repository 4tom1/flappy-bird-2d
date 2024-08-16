#ifndef _FLAPPY_ENGINE_GAMEOBJMANAGER_
#define _FLAPPY_ENGINE_GAMEOBJMANAGER_

#include <vector>

#include <flappy_engine/GameObj.h>

namespace flappy_engine {

	class GameObjManager
	{
		public:

			void AddGameObj(GameObj* new_game_obj);
			void DeleteAll();
			void UpdateAll();
			size_t VectorSize();

			GameObj& operator [](int idx) const;

		private:

			std::vector<GameObj*> game_obj_ptr_vec;
	};
}

#endif
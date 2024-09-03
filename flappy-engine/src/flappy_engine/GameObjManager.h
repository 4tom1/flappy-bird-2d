#ifndef _FLAPPY_ENGINE_GAMEOBJMANAGER_
#define _FLAPPY_ENGINE_GAMEOBJMANAGER_

#include <vector>

#include <flappy_engine/GameObj.h>

namespace flappy_engine {

	class GameObjManager // Mainly game objects updating and game objects sorting. GameObjManager has all initialized game object's addresses to manage them.
	{
		public:

			void AddGameObj(GameObj* new_game_obj);
			// Adds game object's address to vector. (This method is called in game object constructor.)

			void DeleteGameObj(GameObj* old_game_obj);
			// Deletes game object's address to vector. (This method is called in game object destructor.)

			void UpdateAllObj();
			// Calls all game objects' updates methods, including overridden updates and components' updates.

			void Sort();
			// Sorts game objects pointers in position "z" hierarchy. From the smallest to the largest position "z". (It's for rendering queue.)

			size_t Size() const;
			// Returns how many is game objects.

			GameObj* operator[](size_t idx) const;
			// Operator, that simulate vector array of game objects' pointers.

		private:

			std::vector<GameObj*> game_obj_ptr_vec;
			// Vector of game objects' pointers.
	};
}

#endif
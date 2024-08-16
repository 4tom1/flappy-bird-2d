#ifndef _FLAPPY_ENGINE_GAMEOBJ_
#define _FLAPPY_ENGINE_GAMEOBJ_

#include <flappy_engine/GameObjComponents/Sprite.h>
#include <flappy_engine/GameObjComponents/Collider.h>
#include <flappy_engine/GameObjComponents/Transform.h>
#include <flappy_engine/GameObjManager.h>


namespace flappy_engine {

	enum Components
	{
		sprite,
		collider
	};
	
	class GameObj
	{
		public:

			GameObj();
			~GameObj();

			void AddComponent(Components com);

			static void SetGameObjManager(GameObjManager* gom);

			virtual void Update();

			Transform transform;
			
			Sprite* sprite = nullptr;
			Collider* collider = nullptr;
		
		private:

			static GameObjManager* game_obj_manager;
	};
}

#endif
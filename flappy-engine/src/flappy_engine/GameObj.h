#ifndef _FLAPPY_ENGINE_GAMEOBJ_
#define _FLAPPY_ENGINE_GAMEOBJ_

#include <flappy_engine/GameObjComponents/Sprite.h>
#include <flappy_engine/GameObjComponents/Collider.h>
#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Engine;

	enum Component
	{
		sprite,
		collider
	};
	
	class GameObj
	{
		public:

			GameObj();
			~GameObj();

			void AddComponent(Component com);
			void DeleteComponent(Component com);

			static void SetEngine(Engine* engine);

			virtual void Update();

			Transform transform;
			
			Sprite* sprite = nullptr;
			Collider* collider = nullptr;

			static Engine* engine;
	};
}

#endif
#ifndef _FLAPPY_ENGINE_GAMEOBJ_
#define _FLAPPY_ENGINE_GAMEOBJ_

#include <flappy_engine/GameObjComponents/Sprite.h>
#include <flappy_engine/GameObjComponents/Animator.h>
#include <flappy_engine/GameObjComponents/Collider.h>
#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Engine;

	enum Component // Compontent id system.
	{
		sprite,
		collider,
		animator
	};
	
	class GameObj // Game object class to make objects. It can be inherited to override virtual update method and make own constructor.
	{
		public:

			GameObj();
			// Constructor, that sends self address to game object manager.

			~GameObj();
			// Destructor, that delete self address from game object manager.

			void AddComponent(Component com);
			// Adds chosen component and it allocated that component.

			void DeleteComponent(Component com);
			// Delete chosen component if exists.

			virtual void Update();
			// Empty method, that waits to override.

			Transform transform;
			// Transform is component, that all objects have. It contains position and rotation.

			Sprite* sprite = nullptr;
			// Sprite pointer to sprite component.

			Collider* collider = nullptr;
			// Collider pointer to collider component.

			Animator* animator = nullptr;
			// Animator pointer to Animator component.

			static Engine* engine;
			// Engine pointer to receive access to engine parts' methods. (Input, sound, etc.)

		private:

			static void SetEngine(Engine* engine);
			// Sets engine pointer on initilized engine.

			friend class Engine;
			
			// Friendships for hide non-api parts of engine. (It's only for visuals in this project.)
	};
}

#endif
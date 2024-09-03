#ifndef _FLAPPY_ENGINE_COLLIDER_
#define _FLAPPY_ENGINE_COLLIDER_

#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Collider // Collider handle trigger system. It's part of component system. (It has no physics implemented.)
	{
		public:

			Collider(Transform* transform) : transform(transform) {}
			// Default costructor for initializing transform pointer.

			void SetSize(float factor_x, float factor_y);
			// Sets size of collider. X is width, Y  is hight.

			void SetSize(float factor);
			// Sets size of collider. X is width, Y  is hight. X = Y.

			inline bool IsTriggered() const { return is_triggered; }
			// Returns collider / trigger state.

		private:

			void Update(Collider& another_collider);
			// Updates this and other collider state. (If one is triggered, another is too.)

			bool is_triggered = false;
			// Collider / trigger state.

			float x = 0, y = 0;
			// Size in x and y.

			Transform* transform;
			// Transform pointer is initializing in constructor and is pointing on game object's transform.

			friend class GameObjManager;

			// Friendships for hide non-api parts of engine. (It's only for visuals in this project.)
	};
}

#endif
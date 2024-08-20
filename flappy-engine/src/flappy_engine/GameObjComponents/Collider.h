#ifndef _FLAPPY_ENGINE_COLLIDER_
#define _FLAPPY_ENGINE_COLLIDER_

#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Collider
	{
		public:

		typedef Scale Size;

		Collider(Transform* transform) : transform(transform) {}

		void Update(Collider& another_collider);

		void SetSize(float x, float y);
		inline bool IsTriggered();


		private:

		bool is_triggered = false;
		Size size;
		Transform* transform;
	};
}

#endif
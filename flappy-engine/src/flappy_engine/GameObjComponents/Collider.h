#ifndef _FLAPPY_ENGINE_COLLIDER_
#define _FLAPPY_ENGINE_COLLIDER_

#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Collider
	{
		public:

		Collider(Transform* transform) : transform(transform) {}

		void Update(Collider& another_collider);

		void SetSize(float factor_x, float factor_y);
		void SetSize(float factor);

		inline bool IsTriggered() const { return is_triggered; }

		private:

		bool is_triggered = false;
		float x = 0, y = 0;
		Transform* transform;

		friend class Button;
	};
}

#endif
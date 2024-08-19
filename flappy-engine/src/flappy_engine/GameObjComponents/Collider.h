#ifndef _FLAPPY_ENGINE_COLLIDER_
#define _FLAPPY_ENGINE_COLLIDER_

#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Collider
	{
	public:

		Collider(Transform* transform) : transform(transform) {}

	private:

		Transform* transform;
	};
}

#endif
#ifndef _FLAPPY_ENGINE_TRANSFORM_
#define _FLAPPY_ENGINE_TRANSFORM_

#include <flappy_engine/GameObjComponents/Position.h>

namespace flappy_engine {

	class Transform
	{
		public:

			Transform(float x = 0.f, float y = 0.f, float z = 0.f, float angle = 0.f)
			{
				position.x = x;
				position.y = y;
				position.z = z;
				rotation = angle;
			}

			Position position;
			float rotation = 0.f;
	};
}

#endif
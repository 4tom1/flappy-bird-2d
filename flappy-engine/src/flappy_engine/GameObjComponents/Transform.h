#ifndef _FLAPPY_ENGINE_TRANSFORM_
#define _FLAPPY_ENGINE_TRANSFORM_

#include <flappy_engine/GameObjComponents/Position.h>

namespace flappy_engine {

	class Transform
	{
		public:

			void SetPosition3(float x, float y, float z);
			void SetPosition2(float x, float y);

			Position position;
			float rotation = 0.f;
	};
}

#endif
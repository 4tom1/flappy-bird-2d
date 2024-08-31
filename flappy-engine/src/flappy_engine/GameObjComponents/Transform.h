#ifndef _FLAPPY_ENGINE_TRANSFORM_
#define _FLAPPY_ENGINE_TRANSFORM_

namespace flappy_engine {

	struct Position
	{
		Position(float x = 0.f, float y = 0.f, float z = 0.f) : x(x), y(y), z(z) {}
		
		float x, y, z;
	};

	class Transform
	{
		public:

			void SetPosition(float x, float y, float z);
			void SetPosition(float x, float y);

			Position position;
			float rotation = 0.f;
	};
}

#endif
#ifndef _FLAPPY_ENGINE_TRANSFORM_
#define _FLAPPY_ENGINE_TRANSFORM_

namespace flappy_engine {

	struct Scale
	{
		Scale(float x = 1.f, float y = 1.f) : x(x), y(y) {}

		float x, y;
	};

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
			void SetScale(float factor_x, float factor_y);
			void SetScale(float factor);

			Position position;
			float rotation = 0.f;
			Scale scale;
	};
}

#endif
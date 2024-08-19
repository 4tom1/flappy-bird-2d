#ifndef _FLAPPY_ENGINE_TRANSFORM_
#define _FLAPPY_ENGINE_TRANSFORM_

namespace flappy_engine {

	struct Scale
	{
		float x = 1.f, y = 1.f;
	};

	struct Position
	{
		float x = 0.f, y = 0.f, z = 0.f;
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
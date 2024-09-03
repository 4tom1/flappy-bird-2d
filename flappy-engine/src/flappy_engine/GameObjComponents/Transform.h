#ifndef _FLAPPY_ENGINE_TRANSFORM_
#define _FLAPPY_ENGINE_TRANSFORM_

namespace flappy_engine {

	struct Position // Position struct is kind of vector3. It just has 3 float variables: x, y, z.
	{
		Position(float x = 0.f, float y = 0.f, float z = 0.f) : x(x), y(y), z(z) {}

		float x, y, z;
	};

	class Transform
	{
		public:

			void SetPosition(float x, float y, float z);
			// Sets new position.

			void SetPosition(float x, float y);
			// Sets new position.

			Position position;
			// Current object position.

			float rotation = 0.f;
			// Current sprite rotation.
	};
}

#endif
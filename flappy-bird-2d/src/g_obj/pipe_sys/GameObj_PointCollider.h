#ifndef _GAMEOBJ_POINTCOLLIDER_
#define _GAMEOBJ_POINTCOLLIDER_

#include <flappy_engine.h>

namespace flappy_bird_2D {

	class GameObj_PointCollider : public flappy_engine::GameObj
	{
		public:
			GameObj_PointCollider();
			void Update();
			void Stop();
			void Move();

		private:
			static float* speed;
			static bool* move;
	};
}

#endif
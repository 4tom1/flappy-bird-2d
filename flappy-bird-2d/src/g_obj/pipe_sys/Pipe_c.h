#ifndef _GAMEOBJ_PIPE_C_
#define _GAMEOBJ_PIPE_C_

#include <flappy_engine.h>

#include "GameObj_Pipe.h"
#include "GameObj_PointCollider.h"

namespace flappy_bird_2D {

	class GameObj_Pipe_c
	{
		public:
			GameObj_Pipe_c();

			inline flappy_engine::Time LifeTime() { return life_time; }

			GameObj_Pipe pipe1;
			GameObj_Pipe pipe2;
			GameObj_PointCollider point_c;

		private:
			flappy_engine::Time life_time;
			static int pipe_closeness;
	};
}

#endif
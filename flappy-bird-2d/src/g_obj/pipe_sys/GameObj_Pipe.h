#ifndef _GAMEOBJ_PIPE_
#define _GAMEOBJ_PIPE_

#include <flappy_engine.h>
#include "../../Settings.h"

namespace flappy_bird_2D {

	class GameObj_Pipe : public flappy_engine::GameObj
	{
		public:
			GameObj_Pipe();
			void Update();
			void Stop();
			void Move();

		private:
			static float* speed;
			static bool* move;
	};
}

#endif
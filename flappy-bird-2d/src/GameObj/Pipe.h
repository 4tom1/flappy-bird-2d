#ifndef _PIPE_
#define _PIPE_

#include <flappy_engine/GameObj.h>

#include "../GameState.h"

namespace flappy_bird {

	class Pipe
	{
		public:

			Pipe();

			inline bool PipeIsTriggered() { return pipe1.collider->IsTriggered() || pipe2.collider->IsTriggered(); };

			void Move();
			void StartPosition();

			static float Random(int min, int max);

			bool point = true;

			flappy_engine::GameObj pipe1, pipe2;
	};
}

#endif
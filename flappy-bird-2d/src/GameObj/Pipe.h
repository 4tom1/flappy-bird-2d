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

			bool point = true;

			flappy_engine::GameObj pipe1;
			flappy_engine::GameObj pipe2;
	};
}

#endif
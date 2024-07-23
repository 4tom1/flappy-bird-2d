#ifndef _GAMEOBJ_PIPE_
#define _GAMEOBJ_PIPE_

#include <flappy_engine.h>
#include "../../GameEnums.h"

namespace flappy_bird_2D {

	class GameObj_Pipe : public flappy_engine::GameObj
	{
		public:
			GameObj_Pipe();
			void Update();

			static inline bool IsTriggered();

		private:
			static GameState* game_state;
			static bool is_triggered;
	};
}

#endif
#ifndef _PIPEMANAGER_
#define _PIPEMANAGER_

#include <flappy_engine/GameObj.h>

#include "Pipe.h"
#include "../Settings.h"
#include "../GameState.h"

namespace flappy_bird {

	class PipeManager : public flappy_engine::GameObj
	{
		public:

			PipeManager(GameState& game_state, flappy_engine::Position& bird_pos);

			void Update();

			static inline bool PipeIsTriggered() { return pipe_is_triggered; };
			static inline bool PointCheck() { return point; }

		private:

			Pipe pipes[PIPE];

			static bool pipe_is_triggered;
			static bool point;

			flappy_engine::Position const* const bird_pos;
			GameState const* const game_state;
	};
}

#endif
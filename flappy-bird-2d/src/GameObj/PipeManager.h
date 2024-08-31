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

			void Reset();
			void Update();

			inline bool PipeIsTriggered() { return pipe_is_triggered; };
			inline bool PointCheck() { return point; }

		private:

			Pipe pipes[PIPE];

			bool pipe_is_triggered = false;
			bool point = false;

			flappy_engine::Position const* const bird_pos;
			GameState const* const game_state;
	};
}

#endif
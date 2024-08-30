#ifndef _BASE_
#define _BASE_

#include <flappy_engine/GameObj.h>

#include "../GameState.h"

namespace flappy_bird {

	class Base : public flappy_engine::GameObj
	{
		public:
			
			Base(GameState& game_state, flappy_engine::Position& bird_pos);

			void Update();

			bool IsTriggered();

		private:

			flappy_engine::Position const* const bird_pos;
			GameState const * const game_state;
	};
}

#endif
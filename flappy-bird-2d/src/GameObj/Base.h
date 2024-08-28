#ifndef _BASE_
#define _BASE_

#include <flappy_engine/GameObj.h>

#include "../GameState.h"

namespace flappy_bird {

	class Base : public flappy_engine::GameObj
	{
		public:
			
			Base(GameState& game_state);

			void Update();

		private:

			GameState const * const game_state = nullptr;
			float start_pos = 0;
	};
}

#endif
#ifndef _BIRD_
#define _BIRD_

#include <flappy_engine/GameObj.h>

#include "../GameState.h"
#include "../Settings.h"

namespace flappy_bird {

	class Bird : public flappy_engine::GameObj
	{
		public:
			
			Bird(GameState& game_state);
			
			void Jump();
			void Update();	

		private:
			
			void Move();

			float acceleration = 0;
			bool direction = true;
			bool is_jumping = false;
			GameState const * const game_state;
	};
}

#endif
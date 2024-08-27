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
			
			float jump_lenght = 0;
			bool is_jumping = false;
			GameState* game_state;
	};
}

#endif
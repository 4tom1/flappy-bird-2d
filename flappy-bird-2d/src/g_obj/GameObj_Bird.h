#ifndef _GAMEOBJ_BIRD_
#define _GAMEOBJ_BIRD_

#include <flappy_engine.h>
#include "../GameEnums.h"
#include "../Settings.h"

namespace flappy_bird_2D {

	class GameObj_Bird : public flappy_engine::GameObj
	{
		public:
			GameObj_Bird();
			void Update();
			void Jump();
		
		private:
			static GameState* game_state;
			static float* speed;
			static bool* move;
	};
}

#endif
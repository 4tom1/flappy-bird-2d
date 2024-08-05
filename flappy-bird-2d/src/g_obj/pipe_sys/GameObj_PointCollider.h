#ifndef _GAMEOBJ_POINTCOLLIDER_
#define _GAMEOBJ_POINTCOLLIDER_

#include <flappy_engine.h>
#include "../../GameEnums.h"

namespace flappy_bird_2D {

	class GameObj_PointCollider : public flappy_engine::GameObj
	{
		public:
			GameObj_PointCollider();
			void Update();
			
			static inline bool IsTriggered();

		private:
			static GameState* game_state;
			static bool is_triggered;
	};
}

#endif
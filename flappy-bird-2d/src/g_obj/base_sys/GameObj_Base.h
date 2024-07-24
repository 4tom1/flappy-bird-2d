#ifndef _GAMEOBJ_BASE_
#define _GAMEOBJ_BASE_

#include <flappy_engine.h>

#include "../../Settings.h"

namespace flappy_bird_2D {

	class GameObj_Base : public flappy_engine::GameObj
	{
		public:
			GameObj_Base();
			void Update();

		private:
			flappy_engine::Time life_time;
	};
}

#endif
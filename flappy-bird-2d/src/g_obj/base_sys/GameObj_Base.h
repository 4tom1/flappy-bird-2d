#ifndef _GAMEOBJ_BASE_
#define _GAMEOBJ_BASE_

#include <flappy_engine.h>

#include "../../Settings.h"

namespace flappy_bird_2D {

	class GameObj_Base : public flappy_engine::GameObj
	{
		public:
			GameObj_Base();
			GameObj_Base(int);
			void Update();
	};
}

#endif
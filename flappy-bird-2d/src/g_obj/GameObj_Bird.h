#ifndef _GAMEOBJ_BIRD_
#define _GAMEOBJ_BIRD_

#include <flappy_engine.h>

namespace flappy_bird_2D {

	class GameObj_Bird : public flappy_engine::GameObj
	{
		public:

			GameObj_Bird();
			void Update();
			void Jump();
	};
}

#endif
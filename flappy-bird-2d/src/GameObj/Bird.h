#ifndef _BIRD_
#define _BIRD_

#include <flappy_engine/GameObj.h>

#include "../Settings.h"

namespace flappy_bird {

	class Bird : public flappy_engine::GameObj
	{
		public:
			
			Bird();
			void Jump();
			
			float jump_lenght = 0;
	};
}

#endif
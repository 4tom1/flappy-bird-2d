#ifndef _GAMEOBJ_SCORE_
#define _GAMEOBJ_SCORE_

#include <flappy_engine.h>

#include "GameObj_Number.h"


namespace flappy_bird_2D {

	class GameObj_Score
	{
		public:
			GameObj_Score();
		
			GameObj_Number numbers[3];
	};
}

#endif
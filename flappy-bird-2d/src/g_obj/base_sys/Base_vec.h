#ifndef _BASE_VEC_
#define _BASE_VEC_

#include <flappy_engine.h>

#include "GameObj_Base.h"
#include "../../Settings.h"

namespace flappy_bird_2D {

	class Base_vec
	{
		public:
			Base_vec();
	
		private:
			GameObj_Base bases[BASE_QUANTITY];
	};
}

#endif
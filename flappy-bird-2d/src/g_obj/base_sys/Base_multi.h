#ifndef _BASE_MULTI_
#define _BASE_MULTI_

#include <flappy_engine.h>

#include "GameObj_Base.h"
#include "../../Settings.h"

namespace flappy_bird_2D {

	class Base_multi
	{
		public:
			Base_multi();

			void Create();
			void Delete();
			flappy_engine::Time FrontLifeTime();
			
			GameObj_Base base[BASE_QUANTITY];

		private:
			int last;
	};
}

#endif
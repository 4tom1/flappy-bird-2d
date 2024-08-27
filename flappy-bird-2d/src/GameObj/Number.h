#ifndef _NUMBER_
#define _NUMBER_

#include <flappy_engine/GameObj.h>

namespace flappy_bird {

	class Number : public flappy_engine::GameObj
	{
		public:
			
			Number();
	
			void Set(unsigned int number);
	};
}

#endif
#ifndef _DESTROYER_
#define _DESTROYER_

#include <flappy_engine/GameObj.h>

#include "PipeC.h"
#include "../Settings.h"

namespace flappy_bird {

	class Destroyer : public flappy_engine::GameObj
	{
		public:
	
			Destroyer(PipeC** pipe_c);

			void Update();

		private:

			PipeC** pipe_c;
	};
}

#endif
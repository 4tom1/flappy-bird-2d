#ifndef _SPAWNER_
#define _SPAWNER_

#include <flappy_engine/GameObj.h>

#include "PipeC.h"
#include "../Settings.h"

namespace flappy_bird {

	class Spawner : public flappy_engine::GameObj
	{
		public:

			Spawner(PipeC** pipe_c);

			void Update();

		private:

			PipeC** pipe_c;
	};
}

#endif
#ifndef _PIPEC_
#define _PIPEC_

#include <flappy_engine/GameObj.h>

#include "Pipe.h"
#include "PointCollider.h"
#include "../Settings.h"

namespace flappy_bird {

	class PipeC : public flappy_engine::GameObj
	{
		public:

			PipeC(flappy_engine::Position& position);

			void Update();

			Pipe pipe1;
			Pipe pipe2;
			PointCollider point_collider;
	};
}

#endif
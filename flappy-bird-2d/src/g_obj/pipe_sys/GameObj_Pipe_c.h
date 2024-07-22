#ifndef _GAMEOBJ_PIPE_C_
#define _GAMEOBJ_PIPE_C_

#include "GameObj_Pipe.h"
#include "GameObj_PointCollider.h"

namespace flappy_bird_2D {

	class GameObj_Pipe_c
	{
		public:
			GameObj_Pipe_c();
			
			void Stop();
			inline bool PipeIsTriggered();
			inline bool PointColliderIsTriggered();

			GameObj_Pipe pipe1;
			GameObj_Pipe pipe2;
			GameObj_PointCollider point_c;
	};
}

#endif
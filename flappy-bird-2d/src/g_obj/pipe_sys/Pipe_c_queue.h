#ifndef _PIPE_C_STACK_
#define _PIPE_C_STACK_

#include <flappy_engine.h>

#include <queue>

#include "Pipe_c.h"

namespace flappy_bird_2D {

	class GameObj_Pipe_c_queue : public std::queue<GameObj_Pipe_c>
	{
		public:
			GameObj_Pipe_c_queue();

			inline bool PointColliderIsTriggered() { return GameObj_PointCollider::IsTriggered(); }
			inline bool PipeColliderIsTriggered() { return GameObj_Pipe::IsTriggered(); }
			inline flappy_engine::Time LastPipeCreated();
			
			void Delete_Pipe_c();
			void Add_Pipe_c();

		private:
	};
}



#endif
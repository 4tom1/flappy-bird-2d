#ifndef _PIPE_C_STACK_
#define _PIPE_C_STACK_

#include <flappy_engine.h>

#include <queue>

#include "Pipe_c.h"

namespace flappy_bird_2D {

	class Pipe_c_queue : public std::queue<Pipe_c>
	{
		public:

			inline bool PointColliderIsTriggered() { return GameObj_PointCollider::IsTriggered(); }
			inline bool PipeColliderIsTriggered() { return GameObj_Pipe::IsTriggered(); }
			
			void Delete();
			void Create();
			void PipeCSys();
			bool Possible();
			

		private:

			static flappy_engine::Time last_pipe_created;
			static flappy_engine::Time pipe_distance;
	};
}



#endif
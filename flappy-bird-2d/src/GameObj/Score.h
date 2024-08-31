#ifndef _SCORE_
#define _SCORE_

#include "Number.h"

namespace flappy_bird {

	class Score : public flappy_engine::GameObj
	{
		public:
			
			Score(unsigned char* points);

			void Hide();
			void Show();
			void Set();
			void Update();
		
		private:

			Number score[3];
			unsigned char* points;
	};
}

#endif
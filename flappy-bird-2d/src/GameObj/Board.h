#ifndef _BOARD_
#define _BOARD_

#include <flappy_engine/GameObj.h>

#include "Number.h"

namespace flappy_bird {

	class Board : public flappy_engine::GameObj
	{
		public:

			Board(unsigned char* score, unsigned char* best_score);

			void Hide();
			void Show();

		private:

			Number score[3];
			Number best_score[3];
	};
}

#endif
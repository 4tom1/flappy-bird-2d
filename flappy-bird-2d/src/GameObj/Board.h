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
			void Set();

		private:

			Number score[3];
			Number best_score[3];

			unsigned char* points = nullptr;
			unsigned char* best = nullptr;
	};
}

#endif
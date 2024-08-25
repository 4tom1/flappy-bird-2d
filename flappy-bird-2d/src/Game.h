#ifndef _GAME_
#define _GAME_

#include <flappy_engine/flappy_engine.h>

#include "GameObj/Bird.h"
#include "GameObj/Background.h"
#include "GameObj/RestartButton.h"
#include "GameObj/PipeC.h"
#include "GameObj/Base.h"
#include "GameObj/Board.h"
#include "GameObj/Score.h"

namespace flappy_bird {

	enum GameState
	{
		start, playing, game_over
	};

	class Game
	{
		public:	
			
			Game();
			~Game();
			void Run();
		
		private:

			void Start();
			void Playing();
			void GameOver();
			void CreateStartScene();
			void CreatePlayingScene();
			void CreateGameOverScene();

			flappy_engine::Engine* engine;

			GameState game_state;
			unsigned int points = 0;
			unsigned int best_score = 0;

			Bird* bird = nullptr;
			Background* background = nullptr;
			Base* base = nullptr;
			Score* score;
			PipeC* pipe_c[4];
			RestartButton* res_but = nullptr;
			Board* board = nullptr;
	};

}

#endif
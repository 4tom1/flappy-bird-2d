#ifndef _GAME_
#define _GAME_

#include "GameObj/Bird.h"
#include "GameObj/Background.h"
#include "GameObj/RestartButton.h"
#include "GameObj/PipeManager.h"
#include "GameObj/Base.h"
#include "GameObj/Board.h"
#include "GameObj/Score.h"

#include "GameState.h"
#include "Settings.h"

namespace flappy_bird {

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
			void StartScene();
			void PlayingScene();
			void GameOverScene();
			void Reset();
			

			flappy_engine::Engine* engine;

			GameState game_state = start;
			
			unsigned char points[3] = { 0, 0, 0 };
			unsigned char best_score[3] = { 0, 0, 0 };

			Bird* bird = nullptr;
			Background* background = nullptr;
			Base* base = nullptr;
			Score* score = nullptr;
			RestartButton* res_but = nullptr;
			Board* board = nullptr;
			PipeManager* pipe_m = nullptr;
	};
}

#endif
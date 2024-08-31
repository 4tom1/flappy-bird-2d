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
			void RunTest();
		
		private:

			void Start();
			void Playing();
			void GameOver();
			void SetBestScore();

			flappy_engine::Engine* engine;

			GameState game_state = start;
			
			unsigned char points[3] = { 0, 0, 0 };
			unsigned char best_score[3] = { 0, 0, 0 };

			Bird bird = game_state;
			Background background;
			Base base = { game_state, bird.transform.position };
			Score score = points;
			RestartButton res_but;
			Board board = { points, best_score };
			PipeManager pipe_m = { game_state, bird.transform.position };
	};

}

#endif
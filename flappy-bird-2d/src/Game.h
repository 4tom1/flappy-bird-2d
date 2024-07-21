#ifndef _GAME_
#define _GAME_

#include <flappy_engine.h>

namespace flappy_bird_2D {

	class Game
	{
		public:	
			Game();
			void Run();
		
		private:

			enum GameState
			{
				start = 1, playing, game_over
			};

			// functions
			void Update();
			void Start();
			void Playing();
			void GameOver();
			inline bool IsRunning();
			inline void IsRunning(bool);
			void ChangeGameState(GameState);
			void CreateStartScene();
			void CreatePlayingScene();
			void CreateGameOverScene();

			// variables
			bool is_running = true;
			GameState game_state = start;
			int score;
			int best_score;

			GameObj* bird;
			GameObj* background;
			GameObj* score;
			GameObj* board;
			GameObj* ResBut;
			Pipe_stack* pipe_stk;
	};

}

#endif 



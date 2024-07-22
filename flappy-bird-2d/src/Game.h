#ifndef _GAME_
#define _GAME_

#include <flappy_engine.h>

namespace flappy_bird_2D {

	class Game
	{
		public:	
			Game();
			~Game();
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
			inline void SetIsRunning(bool);
			void ChangeGameState(GameState);
			void CreateStartScene();
			void CreatePlayingScene();
			void CreateGameOverScene();

			// variables
			bool is_running = true;
			GameState game_state;
			int score_points;
			int best_score;

			Bird* bird;
			Background* background;
			Score* score;
			Board* board;
			RestartButton* res_but;
			MultiBase* m_base;
			Pipe_c_stack* pipe_c_stk;
	};

}

#endif
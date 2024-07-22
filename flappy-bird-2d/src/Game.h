#ifndef _GAME_
#define _GAME_

#include <flappy_engine.h>
#include "GameEnums.h"

namespace flappy_bird_2D {

	class Game
	{
		public:	
			Game();
			~Game();
			void Run();
		
		private:

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

			GameObj_Bird* bird;
			GameObj_Background* background;
			GameObj_Score* score;
			GameObj_Board* board;
			GameObj_RestartButton* res_but;
			GameObj_Base_multi* base_m;
			GameObj_Pipe_c_stack* pipe_c_stk;
	};

}

#endif
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

			flappy_engine::Time pipe_distance;

			GameObj_Bird* bird;
			GameObj_Background* background;
			GameObj_Score* score;
			GameObj_Board* board;
			GameObj_RestartButton* res_but;
			Base_multi* base_m;
			Pipe_c_queue* pipe_c_q;
	};

}

#endif
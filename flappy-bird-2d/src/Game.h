#ifndef _GAME_
#define _GAME_

#include <flappy_engine.h>

#include "GameEnums.h"

#include "g_obj/GameObj_Bird.h"
#include "g_obj/GameObj_Background.h"
#include "g_obj/GameObj_RestartButton.h"
#include "g_obj/pipe_sys/Pipe_c_queue.h"
#include "g_obj/base_sys/Base_vec.h"
#include "g_obj/score_sys/Board_c.h"
#include "g_obj/score_sys/Score_c.h"


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
			inline bool IsRunning();
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
			GameObj_RestartButton* res_but;
			Score_c* score;
			Board_c* board;
			Base_vec* base_v;
			Pipe_c_queue* pipe_c_q;
	};

}

#endif
#ifndef _FLAPPY_ENGINE_CORE_
#define _FLAPPY_ENGINE_CORE_

#include <flappy-engine/Input.h>
#include <flappy-engine/Renderer.h>
#include <flappy-engine/Sound.h>
#include <flappy-engine/GameObjManager.h>
#include <flappy-engine/Window.h>


namespace flappy_engine {

	class Engine
	{
		public:
			
			Engine(int, int, float);

			void UpdateAllObj();
			void RenderAllObj();
			void DeleteAllObj();
			
			Input input;
			Renderer renderer;
			Window window;
			Sound sound;
			GameObjManager game_obj_manager;
	};

	void InitEngine(int, int, float);
}

#endif
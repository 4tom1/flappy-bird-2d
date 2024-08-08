#ifndef _FLAPPY_ENGINE_CORE_
#define _FLAPPY_ENGINE_CORE_

#include "../Input/Input.h"
#include "../Renderer/Renderer.h"
#include "../Sound/Sound.h"
#include "../GameObjManager/GameObjManager.h"
#include "../Window/Window.h"


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
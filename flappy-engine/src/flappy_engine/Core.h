#ifndef _FLAPPY_ENGINE_CORE_
#define _FLAPPY_ENGINE_CORE_

#include <flappy_engine/Input.h>
#include <flappy_engine/Sound.h>
#include <flappy_engine/GameObjManager.h>
#include <flappy_engine/Window.h>


namespace flappy_engine {

	class Engine
	{
		public:
			
			Engine(unsigned int width, unsigned int high, unsigned int frame_rate, const char* window_name, float volume);

			void UpdateAll();
			void RenderAllObj();
			void DeleteAllObj();
			
			Input input;
			Window window;
			Sound sound;
			GameObjManager game_obj_manager;
	};

	Engine* InitEngine(unsigned int width, unsigned int high, unsigned int frame_rate, const char* window_name, float volume);
}

#endif
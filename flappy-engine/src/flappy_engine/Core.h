/////////////////////////////////////////////////////////////////////////////////
// Core contain main "Engine" class, which has to be initialize to use enigne. //
/////////////////////////////////////////////////////////////////////////////////

#ifndef _FLAPPY_ENGINE_CORE_
#define _FLAPPY_ENGINE_CORE_

#include <flappy_engine/Input.h>
#include <flappy_engine/Sound.h>
#include <flappy_engine/GameObjManager.h>
#include <flappy_engine/Window.h>

namespace flappy_engine {

	Engine* InitEngine(unsigned int width, unsigned int high, unsigned int frame_rate, const char* window_name, float volume);
	// InitEngine is a function to initialize engine and it returns pointer to that allocated engine.
	
	class Engine
	{
		public:
			
			Engine(unsigned int width, unsigned int high, unsigned int frame_rate, const char* window_name, float volume);
			// Engine constructor sets window and volume settings.

			void UpdateAll();
			// This method update window and all existing game objects.

			void RenderAll();
			// This method contain classic rendering loop, and render all game objects' sprites.
			
			Input input;
			// input object handle keyboard and mouse events. (Prepered for this project.)

			Window window;
			// window object create a window and handle its own events. (Close window.)

			Sound sound;
			// sound handle sounds.

			GameObjManager game_obj_manager;
			// game_obj_manager manage game objects. (Details in GameObjManager header.)
	};
}

#endif
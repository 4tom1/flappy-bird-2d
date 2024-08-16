#ifndef _FLAPPY_ENGINE_INPUT_
#define _FLAPPY_ENGINE_INPUT_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <flappy_engine/Window.h>

namespace flappy_engine {
	
	enum Key
	{
		ESC, SPACEBAR
	};
	
	class Input
	{
		public:
			
            bool MouseClick();
			bool IsKeyPressed(Key key);

			void SetWindow(Window* window_ptr);

		private:

			flappy_engine::Window* window;
	};
}

#endif
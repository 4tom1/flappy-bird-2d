#ifndef _FLAPPY_ENGINE_INPUT_
#define _FLAPPY_ENGINE_INPUT_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <flappy_engine/Window.h>

namespace flappy_engine {
	
	enum Key
	{
		ESC, SPACEBAR, LEFT, RIGHT, DOWN, UP
	};
	
	class Input
	{
		public:
			
            bool MouseClick();
			bool IsKeyPressed(Key key);

		private:

			sf::Vector2i GetMousePosition();
			void SetWindow(Window* window_ptr);

			flappy_engine::Window* window;

			friend class Button;
			friend class Engine;
	};
}

#endif
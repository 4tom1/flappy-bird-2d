#ifndef _FLAPPY_ENGINE_INPUT_
#define _FLAPPY_ENGINE_INPUT_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <flappy_engine/Window.h>

namespace flappy_engine {
	
	enum Key // Keyboard key id.
	{
		ESC, SPACEBAR, LEFT, RIGHT, DOWN, UP
	};
	
	class Input // Handle simple input. (For flappy bird purpose.)
	{
		public:
			
            bool MouseClick();
			// Returns true if right or left mouse putton is pressed.

			bool IsKeyPressed(Key key);
			// Returns true if given key is pressed.

		private:

			sf::Vector2i GetMousePosition();
			// Returns vector of mouse local window position.

			void SetWindow(Window* window_ptr);
			// Sets window pointer on given window address.

			flappy_engine::Window* window = nullptr;
			// Window pointer for checking window focus.

			friend class Button;
			friend class Engine;

			// Friendships for hide non-api parts of engine. (It's only for visuals in this project.)
	};
}

#endif
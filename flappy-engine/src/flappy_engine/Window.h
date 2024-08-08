#ifndef _FLAPPY_ENGINE_WINDOW_
#define _FLAPPY_ENGINE_WINDOW_

#include <SFML/Window.hpp>

namespace flappy_engine {

	class Window
	{
		public:

			Window(int, int, const char*);

			void Update();
			bool IsOpen();

		private:

			sf::Window window;
			sf::Event event;
	};
}

#endif
#ifndef _FLAPPY_ENGINE_WINDOW_
#define _FLAPPY_ENGINE_WINDOW_

#include <SFML/Graphics.hpp>

namespace flappy_engine {

	class Window
	{
		public:

			Window(int width, int high, const char* name);

			void Update();
			bool IsOpen();

		private:

			sf::RenderWindow window;
			sf::Event event;
	};
}

#endif
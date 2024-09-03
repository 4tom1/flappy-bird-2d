#ifndef _FLAPPY_ENGINE_WINDOW_
#define _FLAPPY_ENGINE_WINDOW_

#include <SFML/Graphics.hpp>

namespace flappy_engine {

	class Window : public sf::RenderWindow
	{
		public:

			Window(unsigned int width, unsigned int high, const char* name, unsigned int frame_rate);

		private:

			void Update();

			sf::Event event;

			friend class Engine;
	};
}

#endif
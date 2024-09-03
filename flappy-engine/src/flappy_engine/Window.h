#ifndef _FLAPPY_ENGINE_WINDOW_
#define _FLAPPY_ENGINE_WINDOW_

#include <SFML/Graphics.hpp>

namespace flappy_engine {

	class Window : public sf::RenderWindow // SFML window with its own Update method.
	{
		public:

			Window(unsigned int width, unsigned int high, const char* name, unsigned int frame_rate);
			// Window constructor, that sets these parameters.

		private:

			void Update();
			// Handle events every frame.

			sf::Event event;
			// SFML event object to event poll.

			friend class Engine;
			
			// Friendships for hide non-api parts of engine. (It's only for visuals in this project.)
	};
}

#endif
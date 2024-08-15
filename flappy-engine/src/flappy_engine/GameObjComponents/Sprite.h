#ifndef _FLAPPY_ENGINE_SPRITE_
#define _FLAPPY_ENGINE_SPRITE_

#include <SFML/Graphics.hpp>

namespace flappy_engine {

	class Sprite : public sf::Sprite
	{
		public:

			bool Create(const char* file_path);

		private:
			sf::Texture texture;
	};
}

#endif
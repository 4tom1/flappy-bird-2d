#ifndef _FLAPPY_ENGINE_SPRITE_
#define _FLAPPY_ENGINE_SPRITE_

#include <SFML/Graphics.hpp>

#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Sprite : public sf::Sprite
	{
		public:

			Sprite(Transform* transform) : transform(transform) {}

			bool Create(const char* file_path);
			void UpdatePosition();

		private:
			
			sf::Texture texture;
			Transform* transform;
	};
}

#endif
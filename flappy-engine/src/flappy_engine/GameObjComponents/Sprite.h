#ifndef _FLAPPY_ENGINE_SPRITE_
#define _FLAPPY_ENGINE_SPRITE_

#include <SFML/Graphics.hpp>

#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Sprite : public sf::Sprite
	{
		public:

			Sprite(Transform* transform) : transform(transform) {}

			void Create(const char* file_path);

			sf::Vector2f GetSize();
			void DefaultTex();
			void Update();

		private:
			
			sf::Texture texture;
			sf::Transform sf_transform;
			Transform* transform;

			friend class Engine;
	};
}

#endif
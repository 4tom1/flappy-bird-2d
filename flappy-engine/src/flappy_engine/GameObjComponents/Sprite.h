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

		private:
			
			void DefaultTex();
			void Update();

			sf::Texture texture;
			Transform* transform;

			friend class GameObjManager;
			friend class Animator;
	};
}

#endif
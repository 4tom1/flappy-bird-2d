#ifndef _FLAPPY_ENGINE_SPRITE_
#define _FLAPPY_ENGINE_SPRITE_

#include <SFML/Graphics.hpp>

#include <flappy_engine/GameObjComponents/Transform.h>

namespace flappy_engine {

	class Sprite : public sf::Sprite // Every sprite contain self texture. It's part of component system.
	{
		public:

			Sprite(Transform* transform) : transform(transform) {}
			// Default costructor for initializing transform pointer.

			void Create(const char* file_path); 
			// Creates object's sprite by load texture from file.

			sf::Vector2f GetSize();
			// Returns vector of 2 float variables, x and y. X is width, Y  is hight.

		private:
			
			void DefaultTex();
			// Sets this sprite texture, even if is empty. (It's for animator system. When animator stop animation, sets default texture.)

			void Update();
			// Updates position and rotation of sprite.

			sf::Texture texture;
			// Texture of sprite.

			Transform* transform;
			// Transform pointer is initializing in constructor and is pointing on game object's transform.

			friend class GameObjManager;
			friend class Animator;
			
			// Friendships for hide non-api parts of engine. (It's only for visuals in this project.)
	};
}

#endif
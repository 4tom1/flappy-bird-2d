#ifndef _FLAPPY_ENGINE_ANIMATOR_
#define _FLAPPY_ENGINE_ANIMATOR_

#include <flappy_engine/GameObjComponents/Sprite.h>

namespace flappy_engine {
	
	constexpr unsigned int textures_limit = 4;

	class Animator
	{
		public:

			Animator(Sprite* game_obj_sprite) : game_obj_sprite(game_obj_sprite) {}

			void Animation(const char* file_paths[textures_limit], unsigned int frame_per_sec);
			void Play();
			void Stop();

			void Update();

			static void SetFrameRate(unsigned int frame_rate);

		private:

			flappy_engine::Sprite* game_obj_sprite;
			sf::Texture textures[textures_limit];

			bool play = true;

			unsigned int current_frame = 0;
			unsigned int animation_frame_rate = 0;
			unsigned int loop = 0;
			static unsigned int frame_rate;
	};
}

#endif